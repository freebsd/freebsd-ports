/*
 * C-compatible xerbla_ that replaces the Fortran version from LAPACK.
 * The Fortran xerbla_ crashes when called from f2c-translated C code
 * because of incompatible Fortran string argument passing conventions.
 */

#include <stdio.h>

void xerbla_(char *srname, int *info)
{
	fprintf(stderr, " ** On entry to %6s parameter number %2d had an illegal value\n",
		srname, *info);
}
