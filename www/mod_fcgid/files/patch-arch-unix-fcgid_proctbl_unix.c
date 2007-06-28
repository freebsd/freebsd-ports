--- arch/unix/fcgid_proctbl_unix.c.orig	Fri Feb 16 04:34:41 2007
+++ arch/unix/fcgid_proctbl_unix.c	Tue Feb 27 18:33:28 2007
@@ -1,4 +1,5 @@
 #include "fcgid_proctbl.h"
+#include "apr_version.h"
 #include "apr_shm.h"
 #include "apr_global_mutex.h"
 #include "fcgid_global.h"
@@ -17,6 +18,89 @@
 static fcgid_share *_global_memory = NULL;
 static fcgid_global_share *g_global_share = NULL;	/* global information */
 static size_t g_table_size = FCGID_PROC_TABLE_SIZE;
+
+/* apr version 0.x not support apr_shm_remove, I have to copy it from apr version 1.x */
+#if (APR_MAJOR_VERSION < 1)
+#ifdef HAVE_SYS_MMAN_H
+#include <sys/mman.h>
+#endif
+#ifdef HAVE_SYS_IPC_H
+#include <sys/ipc.h>
+#endif
+#ifdef HAVE_SYS_MUTEX_H
+#include <sys/mutex.h>
+#endif
+#ifdef HAVE_SYS_SHM_H
+#include <sys/shm.h>
+#endif
+#if !defined(SHM_R)
+#define SHM_R 0400
+#endif
+#if !defined(SHM_W)
+#define SHM_W 0200
+#endif
+#ifdef HAVE_SYS_FILE_H
+#include <sys/file.h>
+#endif
+
+static apr_status_t apr_shm_remove(const char *filename, apr_pool_t * pool)
+{
+#if APR_USE_SHMEM_SHMGET
+	apr_status_t status;
+	apr_file_t *file;
+	key_t shmkey;
+	int shmid;
+#endif
+
+#if APR_USE_SHMEM_MMAP_TMP
+	return apr_file_remove(filename, pool);
+#endif
+#if APR_USE_SHMEM_MMAP_SHM
+	if (shm_unlink(filename) == -1) {
+		return errno;
+	}
+	return APR_SUCCESS;
+#endif
+#if APR_USE_SHMEM_SHMGET
+	/* Presume that the file already exists; just open for writing */
+	status = apr_file_open(&file, filename, APR_WRITE,
+						   APR_OS_DEFAULT, pool);
+	if (status) {
+		return status;
+	}
+
+	/* ftok() (on solaris at least) requires that the file actually
+	 * exist before calling ftok(). */
+	shmkey = ftok(filename, 1);
+	if (shmkey == (key_t) - 1) {
+		goto shm_remove_failed;
+	}
+
+	apr_file_close(file);
+
+	if ((shmid = shmget(shmkey, 0, SHM_R | SHM_W)) < 0) {
+		goto shm_remove_failed;
+	}
+
+	/* Indicate that the segment is to be destroyed as soon
+	 * as all processes have detached. This also disallows any
+	 * new attachments to the segment. */
+	if (shmctl(shmid, IPC_RMID, NULL) == -1) {
+		goto shm_remove_failed;
+	}
+	return apr_file_remove(filename, pool);
+
+  shm_remove_failed:
+	status = errno;
+	/* ensure the file has been removed anyway. */
+	apr_file_remove(filename, pool);
+	return status;
+#endif
+
+	/* No support for anonymous shm */
+	return APR_ENOTIMPL;
+}
+#endif							/* APR_MAJOR_VERSION<1 */
 
 apr_status_t
 proctable_post_config(server_rec * main_server, apr_pool_t * configpool)
