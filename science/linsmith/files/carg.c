/* carg.f -- translated by f2c (version 20000817).
*/
#include <math.h>
#include <complex.h>

double carg(complex z__)
{
    /* System generated locals */
    double ret_val;

/* april 1977 version.  w. fullerton, c3, los alamos scientific lab. */

    ret_val = (float)0.;
    if (creal(z__) != (float)0. || cimag(z__) != (float)0.) {
	ret_val = atan2(cimag(z__), creal(z__));
    }

    return ret_val;
} /* carg */

