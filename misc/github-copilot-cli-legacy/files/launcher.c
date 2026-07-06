/*
 * launcher.c - GitHub Copilot CLI binary flavor launcher
 *
 * Extracts the bundled copilot JS files and node runtime to a version-specific
 * cache directory and runs them. The bundle (xz-compressed tar) contains the
 * full node binary so no system node installation is required.
 *
 * Node.js SEA (Single Executable Application) cannot be used because
 * postject_find_resource() has no FreeBSD code path.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef PORTVERSION
#define PORTVERSION "unknown"
#endif

#define CACHE_SUBDIR "github-copilot-cli/v" PORTVERSION

extern const char _binary_copilot_bundle_txz_start[];
extern const char _binary_copilot_bundle_txz_end[];

static int
makedirs(const char *path)
{
	char buf[1024];
	char *p;
	struct stat st;

	if (stat(path, &st) == 0)
		return (0);

	snprintf(buf, sizeof(buf), "%s", path);
	for (p = buf + 1; *p != '\0'; p++) {
		if (*p == '/') {
			*p = '\0';
			if (stat(buf, &st) != 0 && mkdir(buf, 0755) != 0 &&
			    errno != EEXIST)
				return (-1);
			*p = '/';
		}
	}
	return (mkdir(buf, 0755) == 0 || errno == EEXIST ? 0 : -1);
}

static int
extract_bundle(const char *destdir)
{
	char tmpdir[1024], archpath[1024];
	const char *data;
	size_t size;
	FILE *f;
	pid_t pid;
	int status;

	/* Write bundle to a temp archive file */
	snprintf(archpath, sizeof(archpath), "%s/.bundle.txz.tmp", destdir);
	data = _binary_copilot_bundle_txz_start;
	size = (size_t)(_binary_copilot_bundle_txz_end -
	    _binary_copilot_bundle_txz_start);

	f = fopen(archpath, "wb");
	if (f == NULL) {
		fprintf(stderr, "copilot: cannot write bundle: %s\n",
		    strerror(errno));
		return (-1);
	}
	if (fwrite(data, 1, size, f) != size) {
		fclose(f);
		unlink(archpath);
		fprintf(stderr, "copilot: bundle write failed\n");
		return (-1);
	}
	fclose(f);

	/* Extract into a temp subdir, then atomically rename */
	snprintf(tmpdir, sizeof(tmpdir), "%s.extracting", destdir);
	makedirs(tmpdir);

	pid = fork();
	if (pid < 0) {
		unlink(archpath);
		return (-1);
	}
	if (pid == 0) {
		execl("/usr/bin/tar", "tar", "-xJf", archpath, "-C", tmpdir,
		    (char *)NULL);
		_exit(127);
	}
	waitpid(pid, &status, 0);
	unlink(archpath);

	if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
		fprintf(stderr, "copilot: bundle extraction failed\n");
		/* cleanup tmpdir */
		pid = fork();
		if (pid == 0) {
			execl("/bin/rm", "rm", "-rf", tmpdir, (char *)NULL);
			_exit(1);
		}
		if (pid > 0)
			waitpid(pid, NULL, 0);
		return (-1);
	}

	/* Atomic rename: tmpdir -> destdir */
	if (rename(tmpdir, destdir) != 0) {
		/* Another process may have already created destdir - that's ok */
		if (errno != EEXIST && errno != ENOTEMPTY) {
			fprintf(stderr, "copilot: rename failed: %s\n",
			    strerror(errno));
			return (-1);
		}
		/* Use existing destdir; clean up tmpdir */
		pid = fork();
		if (pid == 0) {
			execl("/bin/rm", "rm", "-rf", tmpdir, (char *)NULL);
			_exit(1);
		}
		if (pid > 0)
			waitpid(pid, NULL, 0);
	}

	return (0);
}

int
main(int argc, char *argv[])
{
	const char *xdg, *home;
	char cache_dir[1024], node_path[1080], script_path[1080];
	char **new_argv;
	struct stat st;
	int i;

	/* Determine cache directory */
	xdg = getenv("XDG_CACHE_HOME");
	home = getenv("HOME");
	if (xdg != NULL && xdg[0] != '\0')
		snprintf(cache_dir, sizeof(cache_dir), "%s/" CACHE_SUBDIR, xdg);
	else if (home != NULL && home[0] != '\0')
		snprintf(cache_dir, sizeof(cache_dir),
		    "%s/.cache/" CACHE_SUBDIR, home);
	else {
		fprintf(stderr,
		    "copilot: HOME or XDG_CACHE_HOME must be set\n");
		return (1);
	}

	snprintf(node_path, sizeof(node_path), "%s/node", cache_dir);
	snprintf(script_path, sizeof(script_path), "%s/index.js", cache_dir);

	/* Extract bundle if not already done (check for node binary) */
	if (stat(node_path, &st) != 0) {
		if (makedirs(cache_dir) != 0) {
			fprintf(stderr, "copilot: cannot create %s: %s\n",
			    cache_dir, strerror(errno));
			return (1);
		}
		if (extract_bundle(cache_dir) != 0)
			return (1);
	}

	/* Build argument vector for the bundled node */
	new_argv = malloc((size_t)(argc + 2) * sizeof(char *));
	if (new_argv == NULL) {
		fprintf(stderr, "copilot: malloc failed\n");
		return (1);
	}
	new_argv[0] = node_path;
	new_argv[1] = script_path;
	for (i = 1; i < argc; i++)
		new_argv[i + 1] = argv[i];
	new_argv[argc + 1] = NULL;

	execv(node_path, new_argv);

	fprintf(stderr, "copilot: cannot exec %s: %s\n", node_path,
	    strerror(errno));
	return (1);
}
