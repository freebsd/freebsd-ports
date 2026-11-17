/*
 * cc_wrapper that does what Brave's siso handler does for chromium_src/ (see
 * __redirect_cc_handler in brave/build/config/siso/brave_siso_config.star):
 * when brave/chromium_src holds a file of the same name as the source being
 * compiled, compile that one instead.  It is run from the output directory,
 * like every compile step, as
 *
 *	redirect_cc compiler [arguments ...]
 *
 * Brave up to 1.96 shipped a standalone redirect_cc built from //base; 1.97
 * folded it into siso, which does not exist for FreeBSD.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define	CHROMIUM_SRC	"../../brave/chromium_src/"

int
main(int argc, char *argv[])
{
	const char *src, *rest, *p;
	char *override;
	int i;

	if (argc < 2) {
		fprintf(stderr, "usage: redirect_cc compiler [arguments ...]\n");
		return (1);
	}

	for (i = 2; i < argc - 1; i++) {
		if (strcmp(argv[i], "-c") != 0)
			continue;
		src = argv[i + 1];
		rest = NULL;
		if (strncmp(src, "../../", 6) == 0) {
			/* A file in the source tree. */
			rest = src + 6;
		} else if (strncmp(src, "gen/", 4) == 0) {
			/* A generated file, gen/base/buildflags.h say. */
			rest = src + 4;
		} else if ((p = strchr(src, '/')) != NULL &&
		    strncmp(p + 1, "gen/", 4) == 0) {
			/* Generated inside a secondary toolchain. */
			rest = p + 5;
		}
		if (rest != NULL && *rest != '\0') {
			if (asprintf(&override, "%s%s", CHROMIUM_SRC, rest) < 0) {
				perror("redirect_cc");
				return (1);
			}
			if (access(override, F_OK) == 0)
				argv[i + 1] = override;
			else
				free(override);
		}
		break;
	}

	execvp(argv[1], argv + 1);
	perror(argv[1]);
	return (127);
}
