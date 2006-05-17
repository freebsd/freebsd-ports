#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
strverscmp(const char *s1, const char *s2);

int
strverscmp(const char *s1, const char *s2)
{
	static const char *digits = "0123456789";
	int ret;
	long n1, n2;
	size_t p1, p2;

	do {
		p1 = strcspn(s1, digits);
		p2 = strcspn(s2, digits);

		/* Different prefix */
		if ((ret = strncmp(s1, s2, p1)) != 0)
			return ret;

		s1 += p1;
		s2 += p2;
		n1 = strtol(s1, NULL, 10);
		n2 = strtol(s2, NULL, 10);

		if (n1 < n2)
			return -1;
		else if (n1 > n2)
			return 1;

		/* Numbers are equal or not present, try with next ones. */
		p1 = strspn(s1, digits);
		p2 = strspn(s2, digits);
		s1 += p1;
		s2 += p2;
	} while (p1 == p2 && p1 != 0 && p1 != 0);

	return strcmp(s1, s2);
}
