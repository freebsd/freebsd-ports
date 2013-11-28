--- ./inotify.c.orig	2013-11-02 05:06:41.000000000 +0400
+++ ./inotify.c	2013-11-13 17:25:27.000000000 +0400
@@ -15,9 +15,10 @@
  * You should have received a copy of the GNU General Public License
  * along with MiniDLNA. If not, see <http://www.gnu.org/licenses/>.
  */
+
 #include "config.h"
 
-#ifdef HAVE_INOTIFY
+#if defined(HAVE_INOTIFY) || defined(HAVE_SYS_EVENT_H)
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
@@ -31,11 +32,16 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <poll.h>
+#ifdef HAVE_INOTIFY
 #ifdef HAVE_SYS_INOTIFY_H
 #include <sys/inotify.h>
-#else
+#else /*HAVE_SYS_INOTIFY_H*/
 #include "linux/inotify.h"
 #include "linux/inotify-syscalls.h"
+#endif /*HAVE_SYS_INOTIFY_H*/
+#else
+#include <sys/event.h>
+#include <fcntl.h>
 #endif
 #include "libav.h"
 
@@ -49,11 +55,13 @@
 #include "playlist.h"
 #include "log.h"
 
-#define EVENT_SIZE  ( sizeof (struct inotify_event) )
-#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
+#ifdef HAVE_INOTIFY
+#define EVENT_SIZE	( sizeof (struct inotify_event) )
+#define BUF_LEN		 ( 1024 * ( EVENT_SIZE + 16 ) )
 #define DESIRED_WATCH_LIMIT 65536
 
 #define PATH_BUF_SIZE PATH_MAX
+#endif
 
 struct watch
 {
@@ -86,12 +94,34 @@
 	struct watch *nw;
 	int wd;
 
+#ifdef HAVE_INOTIFY
 	wd = inotify_add_watch(fd, path, IN_CREATE|IN_CLOSE_WRITE|IN_DELETE|IN_MOVE);
 	if( wd < 0 )
 	{
 		DPRINTF(E_ERROR, L_INOTIFY, "inotify_add_watch(%s) [%s]\n", path, strerror(errno));
 		return -1;
 	}
+#else /*HAVE_INOTIFY*/
+	wd = open(path, O_RDONLY);
+	if (wd == -1)
+	{
+		DPRINTF(E_ERROR, L_INOTIFY, "inotify_add_watch[kqueue,open](%s) [%s]\n", path, strerror(errno));
+		return -1;
+	}
+
+	struct kevent ke;
+	EV_SET(&ke, wd,
+		EVFILT_VNODE,
+		EV_ADD | EV_ENABLE | EV_CLEAR,
+		NOTE_DELETE | NOTE_WRITE | NOTE_EXTEND /*| NOTE_ATTRB*/,
+		0, NULL);
+
+	if( kevent(fd, &ke, 1, NULL, 0, NULL) == -1 )
+	{
+		DPRINTF(E_ERROR, L_INOTIFY, "inotify_add_watch[kqueue](%s) [%s]\n", path, strerror(errno));
+		return -1;
+	}
+#endif
 
 	nw = malloc(sizeof(struct watch));
 	if( nw == NULL )
@@ -125,7 +155,12 @@
 	for( w = watches; w; w = w->next )
 	{
 		if( strcmp(path, w->path) == 0 )
+#ifdef HAVE_INOTIFY
 			return(inotify_rm_watch(fd, w->wd));
+#else
+			close(w->wd); /* kqueue cleans up events when handle dies*/
+			return(0);
+#endif
 	}
 
 	return 1;
@@ -145,15 +180,14 @@
 int
 inotify_create_watches(int fd)
 {
-	FILE * max_watches;
-	unsigned int num_watches = 0, watch_limit;
+	unsigned int num_watches = 0;
 	char **result;
 	int i, rows = 0;
 	struct media_dir_s * media_path;
 
 	for( media_path = media_dirs; media_path != NULL; media_path = media_path->next )
 	{
-		DPRINTF(E_DEBUG, L_INOTIFY, "Add watch to %s\n", media_path->path);
+		DPRINTF(E_DEBUG, L_INOTIFY, "Setiing up monitoring on %s\n", media_path->path);
 		add_watch(fd, media_path->path);
 		num_watches++;
 	}
@@ -165,7 +199,11 @@
 		num_watches++;
 	}
 	sqlite3_free_table(result);
-		
+
+#ifdef HAVE_INOTIFY
+	FILE * max_watches;
+	unsigned int watch_limit;
+
 	max_watches = fopen("/proc/sys/fs/inotify/max_user_watches", "r");
 	if( max_watches )
 	{
@@ -194,16 +232,17 @@
 			else
 			{
 				DPRINTF(E_WARN, L_INOTIFY, "WARNING: Inotify max_user_watches [%u] is low or close to the number of used watches [%u] "
-				                        "and I do not have permission to increase this limit.  Please do so manually by "
-				                        "writing a higher value into /proc/sys/fs/inotify/max_user_watches.\n", watch_limit, num_watches);
+																"and I do not have permission to increase this limit.	Please do so manually by "
+																"writing a higher value into /proc/sys/fs/inotify/max_user_watches.\n", watch_limit, num_watches);
 			}
 		}
 	}
 	else
 	{
-		DPRINTF(E_WARN, L_INOTIFY, "WARNING: Could not read inotify max_user_watches!  "
-		                        "Hopefully it is enough to cover %u current directories plus any new ones added.\n", num_watches);
+		DPRINTF(E_WARN, L_INOTIFY, "WARNING: Could not read inotify max_user_watches!	"
+														"Hopefully it is enough to cover %u current directories plus any new ones added.\n", num_watches);
 	}
+#endif
 
 	return rows;
 }
@@ -218,7 +257,11 @@
 	while( w )
 	{
 		last_w = w;
+#ifdef HAVE_INOTIFY
 		inotify_rm_watch(fd, w->wd);
+#else
+		close(w->wd); /*kqueue cleans up after fhandle dies*/
+#endif
 		free(w->path);
 		rm_watches++;
 		w = w->next;
@@ -261,10 +304,10 @@
 		while( (e = readdir(ds)) )
 		{
 			if( strcmp(e->d_name, ".") == 0 ||
-			    strcmp(e->d_name, "..") == 0 )
+					strcmp(e->d_name, "..") == 0 )
 				continue;
 			if( (e->d_type == DT_DIR) ||
-			    (e->d_type == DT_UNKNOWN && resolve_unknown_type(dir, NO_MEDIA) == TYPE_DIR) )
+					(e->d_type == DT_UNKNOWN && resolve_unknown_type(dir, NO_MEDIA) == TYPE_DIR) )
 				i += add_dir_watch(fd, dir, e->d_name);
 		}
 	}
@@ -294,6 +337,8 @@
 	struct media_dir_s * media_path = media_dirs;
 	struct stat st;
 
+	DPRINTF(E_DEBUG, L_INOTIFY, "inotify_insert_file: %s @ %s\n", name, path);
+
 	/* Is it cover art for another file? */
 	if( is_image(path) )
 		update_if_album_art(path);
@@ -314,25 +359,25 @@
 	{
 		case ALL_MEDIA:
 			if( !is_image(path) &&
-			    !is_audio(path) &&
-			    !is_video(path) &&
-			    !is_playlist(path) )
+					!is_audio(path) &&
+					!is_video(path) &&
+					!is_playlist(path) )
 				return -1;
 			break;
 		case TYPE_AUDIO:
 			if( !is_audio(path) &&
-			    !is_playlist(path) )
+					!is_playlist(path) )
 				return -1;
 			break;
 		case TYPE_AUDIO|TYPE_VIDEO:
 			if( !is_audio(path) &&
-			    !is_video(path) &&
-			    !is_playlist(path) )
+					!is_video(path) &&
+					!is_playlist(path) )
 			break;
 		case TYPE_AUDIO|TYPE_IMAGES:
 			if( !is_image(path) &&
-			    !is_audio(path) &&
-			    !is_playlist(path) )
+					!is_audio(path) &&
+					!is_playlist(path) )
 				return -1;
 			break;
 		case TYPE_VIDEO:
@@ -341,14 +386,14 @@
 			break;
 		case TYPE_VIDEO|TYPE_IMAGES:
 			if( !is_image(path) &&
-			    !is_video(path) )
+					!is_video(path) )
 				return -1;
 			break;
 		case TYPE_IMAGES:
 			if( !is_image(path) )
 				return -1;
 			break;
-                default:
+								default:
 			return -1;
 			break;
 	}
@@ -371,11 +416,11 @@
 		inotify_remove_file(path);
 	}
 
-	/* Find the parentID.  If it's not found, create all necessary parents. */
+	/* Find the parentID.	If it's not found, create all necessary parents. */
 	len = strlen(path)+1;
 	if( !(path_buf = malloc(len)) ||
-	    !(last_dir = malloc(len)) ||
-	    !(base_name = malloc(len)) )
+			!(last_dir = malloc(len)) ||
+			!(base_name = malloc(len)) )
 		return -1;
 	base_copy = base_name;
 	while( depth )
@@ -386,9 +431,9 @@
 
 		do
 		{
-			//DEBUG DPRINTF(E_DEBUG, L_INOTIFY, "Checking %s\n", parent_buf);
+			/*DEBUG DPRINTF(E_DEBUG, L_INOTIFY, "Checking %s\n", parent_buf);*/
 			id = sql_get_text_field(db, "SELECT OBJECT_ID from OBJECTS o left join DETAILS d on (d.ID = o.DETAIL_ID)"
-			                            " where d.PATH = '%q' and REF_ID is NULL", parent_buf);
+																	" where d.PATH = '%q' and REF_ID is NULL", parent_buf);
 			if( id )
 			{
 				if( !depth )
@@ -421,13 +466,13 @@
 
 	if( !depth )
 	{
-		//DEBUG DPRINTF(E_DEBUG, L_INOTIFY, "Inserting %s\n", name);
+		DPRINTF(E_DEBUG, L_INOTIFY, "Inserting %s\n", name);
 		insert_file(name, path, id+2, get_next_available_id("OBJECTS", id));
 		sqlite3_free(id);
 		if( (is_audio(path) || is_playlist(path)) && next_pl_fill != 1 )
 		{
 			next_pl_fill = time(NULL) + 120; // Schedule a playlist scan for 2 minutes from now.
-			//DEBUG DPRINTF(E_WARN, L_INOTIFY,  "Playlist scan scheduled for %s", ctime(&next_pl_fill));
+			//DEBUG DPRINTF(E_WARN, L_INOTIFY,	"Playlist scan scheduled for %s", ctime(&next_pl_fill));
 		}
 	}
 	return depth;
@@ -446,6 +491,8 @@
 	struct media_dir_s* media_path;
 	struct stat st;
 
+	DPRINTF(E_DEBUG, L_INOTIFY, "inotify_insert_directory: %s @ %s\n", name, path);
+
 	if( access(path, R_OK|X_OK) != 0 )
 	{
 		DPRINTF(E_WARN, L_INOTIFY, "Could not access %s [%s]\n", path, strerror(errno));
@@ -459,7 +506,7 @@
 
  	parent_buf = strdup(path);
 	id = sql_get_text_field(db, "SELECT OBJECT_ID from OBJECTS o left join DETAILS d on (d.ID = o.DETAIL_ID)"
-	                            " where d.PATH = '%q' and REF_ID is NULL", dirname(parent_buf));
+															" where d.PATH = '%q' and REF_ID is NULL", dirname(parent_buf));
 	if( !id )
 		id = sqlite3_mprintf("%s", BROWSEDIR_ID);
 	insert_directory(name, path, BROWSEDIR_ID, id+2, get_next_available_id("OBJECTS", id));
@@ -538,9 +585,12 @@
 	int64_t detailID;
 	int rows, playlist;
 
+	DPRINTF(E_DEBUG, L_INOTIFY, "inotify_remove_file: %s\n", path);
+
 	if( ends_with(path, ".srt") )
 	{
-		return sql_exec(db, "DELETE from CAPTIONS where PATH = '%q'", path);
+		rows = sql_exec(db, "DELETE from CAPTIONS where PATH = '%q'", path);
+		return rows;
 	}
 	/* Invalidate the scanner cache so we don't insert files into non-existent containers */
 	valid_cache = 0;
@@ -554,27 +604,25 @@
 	{
 		sql_exec(db, "DELETE from PLAYLISTS where ID = %lld", detailID);
 		sql_exec(db, "DELETE from DETAILS where ID ="
-		             " (SELECT DETAIL_ID from OBJECTS where OBJECT_ID = '%s$%llX')",
-		         MUSIC_PLIST_ID, detailID);
+								 " (SELECT DETAIL_ID from OBJECTS where OBJECT_ID = '%s$%llX')",
+						 MUSIC_PLIST_ID, detailID);
 		sql_exec(db, "DELETE from OBJECTS where OBJECT_ID = '%s$%llX' or PARENT_ID = '%s$%llX'",
-		         MUSIC_PLIST_ID, detailID, MUSIC_PLIST_ID, detailID);
+						 MUSIC_PLIST_ID, detailID, MUSIC_PLIST_ID, detailID);
 	}
 	else
 	{
 		/* Delete the parent containers if we are about to empty them. */
-		snprintf(sql, sizeof(sql), "SELECT PARENT_ID from OBJECTS where DETAIL_ID = %lld"
-		                           " and PARENT_ID not like '64$%%'",
-		                           (long long int)detailID);
+		snprintf(sql, sizeof(sql), "SELECT PARENT_ID from OBJECTS where DETAIL_ID = %lld", (long long int)detailID);
 		if( (sql_get_table(db, sql, &result, &rows, NULL) == SQLITE_OK) )
 		{
 			int i, children;
-			for( i = 1; i <= rows; i++ )
+			for( i=1; i <= rows; i++ )
 			{
 				/* If it's a playlist item, adjust the item count of the playlist */
 				if( strncmp(result[i], MUSIC_PLIST_ID, strlen(MUSIC_PLIST_ID)) == 0 )
 				{
 					sql_exec(db, "UPDATE PLAYLISTS set FOUND = (FOUND-1) where ID = %d",
-					         atoi(strrchr(result[i], '$') + 1));
+									 atoi(strrchr(result[i], '$') + 1));
 				}
 
 				children = sql_get_int_field(db, "SELECT count(*) from OBJECTS where PARENT_ID = '%s'", result[i]);
@@ -582,6 +630,8 @@
 					continue;
 				if( children < 2 )
 				{
+					sql_exec(db, "DELETE from DETAILS where ID ="
+											 " (SELECT DETAIL_ID from OBJECTS where OBJECT_ID = '%s')", result[i]);
 					sql_exec(db, "DELETE from OBJECTS where OBJECT_ID = '%s'", result[i]);
 
 					ptr = strrchr(result[i], '$');
@@ -589,6 +639,8 @@
 						*ptr = '\0';
 					if( sql_get_int_field(db, "SELECT count(*) from OBJECTS where PARENT_ID = '%s'", result[i]) == 0 )
 					{
+						sql_exec(db, "DELETE from DETAILS where ID ="
+												 " (SELECT DETAIL_ID from OBJECTS where OBJECT_ID = '%s')", result[i]);
 						sql_exec(db, "DELETE from OBJECTS where OBJECT_ID = '%s'", result[i]);
 					}
 				}
@@ -613,11 +665,13 @@
 	int64_t detailID = 0;
 	int rows, i, ret = 1;
 
+	DPRINTF(E_DEBUG, L_INOTIFY, "inotify_remove_directory: %s\n", path);
+
 	/* Invalidate the scanner cache so we don't insert files into non-existent containers */
 	valid_cache = 0;
 	remove_watch(fd, path);
 	sql = sqlite3_mprintf("SELECT ID from DETAILS where (PATH > '%q/' and PATH <= '%q/%c')"
-	                      " or PATH = '%q'", path, path, 0xFF, path);
+												" or PATH = '%q'", path, path, 0xFF, path);
 	if( (sql_get_table(db, sql, &result, &rows, NULL) == SQLITE_OK) )
 	{
 		if( rows )
@@ -639,6 +693,7 @@
 	return ret;
 }
 
+#ifdef HAVE_INOTIFY
 void *
 start_inotify()
 {
@@ -649,7 +704,7 @@
 	int length, i = 0;
 	char * esc_name = NULL;
 	struct stat st;
-        
+
 	pollfds[0].fd = inotify_init();
 	pollfds[0].events = POLLIN;
 
@@ -664,13 +719,13 @@
 	}
 	inotify_create_watches(pollfds[0].fd);
 	if (setpriority(PRIO_PROCESS, 0, 19) == -1)
-		DPRINTF(E_WARN, L_INOTIFY,  "Failed to reduce inotify thread priority\n");
+		DPRINTF(E_WARN, L_INOTIFY,	"Failed to reduce inotify thread priority\n");
 	sqlite3_release_memory(1<<31);
 	av_register_all();
-        
+
 	while( !quitting )
 	{
-                length = poll(pollfds, 1, timeout);
+		length = poll(pollfds, 1, timeout);
 		if( !length )
 		{
 			if( next_pl_fill && (time(NULL) >= next_pl_fill) )
@@ -682,14 +737,14 @@
 		}
 		else if( length < 0 )
 		{
-                        if( (errno == EINTR) || (errno == EAGAIN) )
-                                continue;
-                        else
+			if( (errno == EINTR) || (errno == EAGAIN) )
+				continue;
+			else
 				DPRINTF(E_ERROR, L_INOTIFY, "read failed!\n");
 		}
 		else
 		{
-			length = read(pollfds[0].fd, buffer, BUF_LEN);  
+			length = read(pollfds[0].fd, buffer, BUF_LEN);
 		}
 
 		i = 0;
@@ -707,12 +762,12 @@
 				sprintf(path_buf, "%s/%s", get_path_from_wd(event->wd), event->name);
 				if ( event->mask & IN_ISDIR && (event->mask & (IN_CREATE|IN_MOVED_TO)) )
 				{
-					DPRINTF(E_DEBUG, L_INOTIFY,  "The directory %s was %s.\n",
+					DPRINTF(E_DEBUG, L_INOTIFY,	"The directory %s was %s.\n",
 						path_buf, (event->mask & IN_MOVED_TO ? "moved here" : "created"));
 					inotify_insert_directory(pollfds[0].fd, esc_name, path_buf);
 				}
 				else if ( (event->mask & (IN_CLOSE_WRITE|IN_MOVED_TO|IN_CREATE)) &&
-				          (lstat(path_buf, &st) == 0) )
+									(lstat(path_buf, &st) == 0) )
 				{
 					if( S_ISLNK(st.st_mode) )
 					{
@@ -726,7 +781,7 @@
 					else if( event->mask & (IN_CLOSE_WRITE|IN_MOVED_TO) && st.st_size > 0 )
 					{
 						if( (event->mask & IN_MOVED_TO) ||
-						    (sql_get_int_field(db, "SELECT TIMESTAMP from DETAILS where PATH = '%q'", path_buf) != st.st_mtime) )
+								(sql_get_int_field(db, "SELECT TIMESTAMP from DETAILS where PATH = '%q'", path_buf) != st.st_mtime) )
 						{
 							DPRINTF(E_DEBUG, L_INOTIFY, "The file %s was %s.\n",
 								path_buf, (event->mask & IN_MOVED_TO ? "moved here" : "changed"));
@@ -755,4 +810,234 @@
 
 	return 0;
 }
+#else
+void *
+start_kqueue()
+{
+	int global_kqueue_handle = -1;
+
+	global_kqueue_handle = kqueue();
+	if ( global_kqueue_handle < 0 )
+	{
+		DPRINTF(E_ERROR, L_INOTIFY, "kqueue() failed: %s\n", strerror(errno));
+		return 0;
+	}
+
+	while( scanning )
+	{
+		if( quitting )
+			goto quitting;
+		
+		DPRINTF(E_DEBUG, L_INOTIFY, "..waiting for scanning to complete...\n");
+		sleep(1);
+	}
+
+	DPRINTF(E_DEBUG, L_INOTIFY, "GOING WILD!\n");
+
+	inotify_create_watches(global_kqueue_handle);
+	if (setpriority(PRIO_PROCESS, 0, 19) == -1)
+		DPRINTF(E_WARN, L_INOTIFY,	"Failed to reduce kqueue thread priority\n");
+	sqlite3_release_memory(1<<31);
+	av_register_all();
+
+	while( !quitting )
+	{
+		struct kevent ke;
+		if ( kevent(global_kqueue_handle, NULL, 0, &ke, 1, NULL) == -1 )
+		{
+			DPRINTF(E_WARN, L_INOTIFY,	"kevent polling failure: %s\n", strerror(errno));
+			continue;
+		}
+
+		/*DPRINTF(E_DEBUG, L_INOTIFY,	"GOT KEVENT:\n"
+			"ident=0x%X, filter=0x%X, flags=0x%X, fflags=0x%X, data=0x%X, udata=0x%X\n", 
+			ke.ident, ke.filter, ke.flags, ke.fflags, ke.data, ke.udata);*/
+
+		char* dir_path = get_path_from_wd(ke.ident);
+		if (dir_path == NULL)
+		{
+			DPRINTF(E_ERROR, L_INOTIFY, "Path with FD=0x%X can't be resolved.\n", ke.ident);
+			continue;
+		}
+
+		if (ke.fflags & NOTE_DELETE)
+		{
+			DPRINTF(E_DEBUG, L_INOTIFY, "Path [%s] deleted.\n", dir_path);
+			inotify_remove_directory(ke.ident, dir_path);
+		}
+		else if ((ke.fflags & (NOTE_WRITE | NOTE_LINK)) == (NOTE_WRITE | NOTE_LINK))
+		{
+			DPRINTF(E_DEBUG, L_INOTIFY, "Path [%s] content updated (directory).\n", dir_path);
+
+			char * sql;
+			char **result;
+			int i, rows;
+			sql = sqlite3_mprintf("SELECT PATH from DETAILS where (PATH > '%q/' and PATH <= '%q/%c')"
+				" and SIZE = ''", dir_path, dir_path, 0xFF);
+			if( (sql_get_table(db, sql, &result, &rows, NULL) != SQLITE_OK) )
+			{
+				DPRINTF(E_WARN, L_INOTIFY, "Read state [%s]: Query failed, not updating\n", dir_path);
+				sqlite3_free(sql);
+				continue;
+			}
+
+			for( i=1; i <= rows; i++ )
+			{
+				DPRINTF(E_DEBUG, L_INOTIFY, "Indexed content: %s\n", result[i]);
+				if (access(result[i], R_OK) == -1)
+				{
+					/* actually, global_kqueue_handle is not used here */
+					inotify_remove_directory(global_kqueue_handle, result[i]);
+				}
+			}
+
+			DIR* d;
+			struct dirent * entry;
+			d = opendir(dir_path);
+			if (!d)
+			{
+				DPRINTF(E_ERROR, L_INOTIFY, "Can't list [%s] (%s)\n", dir_path, strerror(errno));
+				continue;
+			}
+
+			for ( entry = readdir(d); entry != NULL; entry = readdir(d) )
+			{
+				if ( (entry->d_type == DT_DIR) &&
+					(strcmp(entry->d_name, "..") != 0) &&
+					(strcmp(entry->d_name, ".") != 0) )
+				{
+					char tmp_path[PATH_MAX];
+					int result_path_len;
+
+					result_path_len = snprintf(tmp_path, PATH_MAX,
+						"%s/%s", dir_path, entry->d_name);
+					if (result_path_len >= PATH_MAX)
+					{
+						DPRINTF(E_ERROR, L_INOTIFY, "File path too long for %s!", entry->d_name);
+						continue;
+					}
+
+					DPRINTF(E_DEBUG, L_INOTIFY, "Walking %s\n", tmp_path);
+					char found_flag = 0;
+					for( i=1; i <= rows; i++ )
+					{
+						if (strcmp(result[i], tmp_path) == 0)
+						{
+							found_flag = 1;
+							break;
+						}
+					}
+
+					if ( !found_flag )
+					{
+						char * esc_name = NULL;
+						esc_name = modifyString(strdup(entry->d_name), "&", "&amp;amp;");
+						inotify_insert_directory(global_kqueue_handle, esc_name, tmp_path);
+						free(esc_name);
+					}
+				}
+			}
+
+			closedir(d);
+
+			sqlite3_free_table(result);
+			sqlite3_free(sql);
+		}
+		else if (ke.fflags & NOTE_WRITE)
+		{
+			DPRINTF(E_DEBUG, L_INOTIFY, "Path [%s] content updated (file).\n", dir_path);
+
+			char * sql;
+			char **result;
+			int i, rows;
+			sql = sqlite3_mprintf("SELECT PATH from DETAILS where (PATH > '%q/' and PATH <= '%q/%c')"
+				" and SIZE <> ''", dir_path, dir_path, 0xFF);
+			if( (sql_get_table(db, sql, &result, &rows, NULL) != SQLITE_OK) )
+			{
+				DPRINTF(E_WARN, L_INOTIFY, "Read state [%s]: Query failed, not updating\n", dir_path);
+				sqlite3_free(sql);
+				continue;
+			}
+
+			for( i=1; i <= rows; i++ )
+			{
+				DPRINTF(E_DEBUG, L_INOTIFY, "Indexed content: %s\n", result[i]);
+				if (access(result[i], R_OK) == -1) /*oops, our file is gone*/
+				{
+					inotify_remove_file(result[i]);
+				}
+			}
+
+			DIR* d;
+			struct dirent * entry;
+			d = opendir(dir_path);
+			if (!d)
+			{
+				DPRINTF(E_ERROR, L_INOTIFY, "Can't list [%s] (%s)\n", dir_path, strerror(errno));
+				continue;
+			}
+
+			for ( entry = readdir(d); entry != NULL; entry = readdir(d) )
+			{
+				if ( (entry->d_type == DT_REG) ||
+				     (entry->d_type == DT_LNK) )
+				{
+					char tmp_path[PATH_MAX];
+					int result_path_len;
+
+					result_path_len = snprintf(tmp_path, PATH_MAX,
+						"%s/%s", dir_path, entry->d_name);
+					if (result_path_len >= PATH_MAX)
+					{
+						DPRINTF(E_ERROR, L_INOTIFY, "File path too long for %s!", entry->d_name);
+						continue;
+					}
+
+					DPRINTF(E_DEBUG, L_INOTIFY, "Walking %s\n", tmp_path);
+
+					char found_flag = 0;
+					for( i=1; i <= rows; i++ )
+					{
+						if (strcmp(result[i], tmp_path) == 0)
+						{
+							found_flag = 1;
+							break;
+						}
+					}
+
+					if ( !found_flag )
+					{
+						char * esc_name = NULL;
+						struct stat st;
+
+						if( stat(tmp_path, &st) != 0 )
+						{
+							DPRINTF(E_ERROR, L_INOTIFY, "'%s' disappeared!", tmp_path);
+							continue;
+						}
+
+						esc_name = modifyString(strdup(entry->d_name), "&", "&amp;amp;");
+						if ( S_ISDIR(st.st_mode) )
+							inotify_insert_directory(global_kqueue_handle, esc_name, tmp_path);
+						else
+							inotify_insert_file(esc_name, tmp_path);
+						free(esc_name);
+					}
+				}
+			}
+
+			closedir(d);
+
+			sqlite3_free_table(result);
+			sqlite3_free(sql);
+		}
+	}
+	inotify_remove_watches(global_kqueue_handle);
+quitting:
+
+	return 0;
+}
 #endif
+
+#endif // defined(HAVE_INOTIFY) || defined(HAVE_SYS_EVENT_H)
+
