/*
 * PQescapeString implementation is from
 * <URL:http://cert.uni-stuttgart.de/doc/postgresql/escape/>
 * It will be available in a later release of PostGreSQL.
 */
#if !defined(HAVE_PQESCAPESTRING)
#include <sys/types.h>

/* Quoting strings before inclusion in queries. */
size_t PQescapeString (char *to, const char *from, size_t length);

/* ---------------
 * Escaping arbitrary strings to get valid SQL strings/identifiers.
 *
 * Replaces "\\" with "\\\\", "\0" with "\\0", and "'" with "''".
 * length is the length of the buffer pointed to by
 * from.  The buffer at to must be at least 2*length + 1 characters
 * long.  A terminating NUL character is written.
 * ---------------
 */

size_t
PQescapeString (char *to, const char *from, size_t length)
{
	const char *source = from;
	char *target = to;
	unsigned int remaining = length;

	while (remaining > 0) {
		switch (*source) {
		case '\0':
			*target = '\\';
			target++;
			*target = '0';
			/* target and remaining are updated below. */
			break;
			
		case '\\':
			*target = '\\';
			target++;
			*target = '\\';
			/* target and remaining are updated below. */
			break;

		case '\'':
			*target = '\'';
			target++;
			*target = '\'';
			/* target and remaining are updated below. */
			break;

		default:
			*target = *source;
			/* target and remaining are updated below. */
		}
		source++;
		target++;
		remaining--;
	}

	/* Write the terminating NUL character. */
	*target = '\0';
	
	return target - to;
}
#endif /* !defined(HAVE_PQESCAPESTRING) */
