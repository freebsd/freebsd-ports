/* example1.f -- translated by f2c (version 20000817).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <mpi.h>

#ifdef __cplusplus
extern "C" {
#include <blas.h>
#include <lapack.h>
#include <pblas.h>
#include <PBpblas.h>
#include <PBtools.h>
#include <PBblacs.h>
#include <scalapack.h>
#endif
#include "g2c.h"

/* Table of constant values */

static integer c__9 = 9;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__5 = 5;
static integer c__1 = 1;
static doublereal c_b70 = 1.;
static doublereal c_b75 = -1.;
static integer c_n1 = -1;

/* Main program */ int MAIN__()
{
    /* Initialized data */

    static integer nprow = 2;
    static integer npcol = 3;

    /* Format strings */
    static char fmt_9999[] = "(/\002ScaLAPACK Example Program #1 -- May 1, 1\
997\002)";
    static char fmt_9998[] = "(/\002Solving Ax=b where A is a \002,i3,\002 b\
y \002,i3,\002 matrix with a block size of \002,i3)";
    static char fmt_9997[] = "(\002Running on \002,i3,\002 processes, where \
the process grid\002,\002 is \002,i3,\002 by \002,i3)";
    static char fmt_9996[] = "(/\002INFO code returned by PDGESV = \002,i3)";
    static char fmt_9995[] = "(/\002According to the normalized residual the\
 solution is correct.\002)";
    static char fmt_9993[] = "(/\002||A*x - b|| / ( ||x||*||A||*eps*N ) =\
 \002,1p,e16.8)";
    static char fmt_9994[] = "(/\002According to the normalized residual the\
 solution is incorrect.\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer info, ipiv[7];
    extern /* Subroutine */ int descinit_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
    static doublereal work[5], a[20]	/* was [5][4] */, b[5]	/* was [5][1] 
	    */;
    static integer desca[9], descb[9];
    static doublereal resid, anorm, bnorm, a0[20]	/* was [5][4] */, b0[
	    5]	/* was [5][1] */;
    static integer mycol, ictxt;
    static doublereal xnorm;
    static integer myrow;
    extern /* Subroutine */ int pdgemm_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, doublereal *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    ftnlen, ftnlen), pdgesv_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *, integer *, integer *, integer *), blacs_exit__(integer *), 
	    blacs_gridinfo__(integer *, integer *, integer *, integer *, 
	    integer *), blacs_gridexit__(integer *);
    static doublereal eps;
    extern doublereal pdlamch_(integer *, char *, ftnlen), pdlange_(char *, 
	    integer *, integer *, doublereal *, integer *, integer *, integer 
	    *, doublereal *, ftnlen);
    extern /* Subroutine */ int pdlacpy_(char *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, ftnlen), sl_init__(integer *, 
	    integer *, integer *), matinit_(doublereal *, integer *, 
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___14 = { 0, 6, 0, fmt_9999, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_9998, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_9997, 0 };
    static cilist io___17 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___24 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___25 = { 0, 6, 0, fmt_9993, 0 };
    static cilist io___26 = { 0, 6, 0, fmt_9994, 0 };
    static cilist io___27 = { 0, 6, 0, fmt_9993, 0 };



/*     Example Program solving Ax=b via ScaLAPACK routine PDGESV */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. Local Arrays .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Data statements .. */
/*     .. */
/*     .. Executable Statements .. */

/*     INITIALIZE THE PROCESS GRID */

    sl_init__(&ictxt, &nprow, &npcol);
    blacs_gridinfo__(&ictxt, &nprow, &npcol, &myrow, &mycol);

/*     If I'm not in the process grid, go to the end of the program */

    if (myrow == -1) {
	goto L10;
    }

/*     DISTRIBUTE THE MATRIX ON THE PROCESS GRID */
/*     Initialize the array descriptors for the matrices A and B */

    descinit_(desca, &c__9, &c__9, &c__2, &c__2, &c__0, &c__0, &ictxt, &c__5, 
	    &info);
    descinit_(descb, &c__9, &c__1, &c__2, &c__1, &c__0, &c__0, &ictxt, &c__5, 
	    &info);

/*     Generate matrices A and B and distribute to the process grid */

    matinit_(a, desca, b, descb);

/*     Make a copy of A and B for checking purposes */

    pdlacpy_("All", &c__9, &c__9, a, &c__1, &c__1, desca, a0, &c__1, &c__1, 
	    desca, (ftnlen)3);
    pdlacpy_("All", &c__9, &c__1, b, &c__1, &c__1, descb, b0, &c__1, &c__1, 
	    descb, (ftnlen)3);

/*     CALL THE SCALAPACK ROUTINE */
/*     Solve the linear system A * X = B */

    pdgesv_(&c__9, &c__1, a, &c__1, &c__1, desca, ipiv, b, &c__1, &c__1, 
	    descb, &info);

    if (myrow == 0 && mycol == 0) {
	s_wsfe(&io___14);
	e_wsfe();
	s_wsfe(&io___15);
	do_fio(&c__1, (char *)&c__9, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__9, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&c__2, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___16);
	i__1 = nprow * npcol;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nprow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&npcol, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___17);
	do_fio(&c__1, (char *)&info, (ftnlen)sizeof(integer));
	e_wsfe();
    }

/*     Compute residual ||A * X  - B|| / ( ||X|| * ||A|| * eps * N ) */

    eps = pdlamch_(&ictxt, "Epsilon", (ftnlen)7);
    anorm = pdlange_("I", &c__9, &c__9, a, &c__1, &c__1, desca, work, (ftnlen)
	    1);
    bnorm = pdlange_("I", &c__9, &c__1, b, &c__1, &c__1, descb, work, (ftnlen)
	    1);
    pdgemm_("N", "N", &c__9, &c__1, &c__9, &c_b70, a0, &c__1, &c__1, desca, b,
	     &c__1, &c__1, descb, &c_b75, b0, &c__1, &c__1, descb, (ftnlen)1, 
	    (ftnlen)1);
    xnorm = pdlange_("I", &c__9, &c__1, b0, &c__1, &c__1, descb, work, (
	    ftnlen)1);
    resid = xnorm / (anorm * bnorm * eps * 9.);

    if (myrow == 0 && mycol == 0) {
	if (resid < 10.) {
	    s_wsfe(&io___24);
	    e_wsfe();
	    s_wsfe(&io___25);
	    do_fio(&c__1, (char *)&resid, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else {
	    s_wsfe(&io___26);
	    e_wsfe();
	    s_wsfe(&io___27);
	    do_fio(&c__1, (char *)&resid, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }

/*     RELEASE THE PROCESS GRID */
/*     Free the BLACS context */

    blacs_gridexit__(&ictxt);
L10:

/*     Exit the BLACS */

    blacs_exit__(&c__0);

    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* Subroutine */ int matinit_(doublereal *aa, integer *desca, doublereal *b, 
	integer *descb)
{
    static doublereal a, c__, k, l, p, s;
    static integer npcol, mycol, ictxt, nprow, myrow, mxllda;
    extern /* Subroutine */ int blacs_gridinfo__(integer *, integer *, 
	    integer *, integer *, integer *);


/*     MATINIT generates and distributes matrices A and B (depicted in */
/*     Figures 2.5 and 2.6) to a 2 x 3 process grid */

/*     .. Array Arguments .. */
/*     .. */
/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Executable Statements .. */

    /* Parameter adjustments */
    --descb;
    --b;
    --desca;
    --aa;

    /* Function Body */
    ictxt = desca[2];
    blacs_gridinfo__(&ictxt, &nprow, &npcol, &myrow, &mycol);

    s = 19.;
    c__ = 3.;
    a = 1.;
    l = 12.;
    p = 16.;
    k = 11.;

    mxllda = desca[9];

    if (myrow == 0 && mycol == 0) {
	aa[1] = s;
	aa[2] = -s;
	aa[3] = -s;
	aa[4] = -s;
	aa[5] = -s;
	aa[mxllda + 1] = c__;
	aa[mxllda + 2] = c__;
	aa[mxllda + 3] = -c__;
	aa[mxllda + 4] = -c__;
	aa[mxllda + 5] = -c__;
	aa[(mxllda << 1) + 1] = a;
	aa[(mxllda << 1) + 2] = a;
	aa[(mxllda << 1) + 3] = a;
	aa[(mxllda << 1) + 4] = a;
	aa[(mxllda << 1) + 5] = -a;
	aa[mxllda * 3 + 1] = c__;
	aa[mxllda * 3 + 2] = c__;
	aa[mxllda * 3 + 3] = c__;
	aa[mxllda * 3 + 4] = c__;
	aa[mxllda * 3 + 5] = -c__;
	b[1] = 0.;
	b[2] = 0.;
	b[3] = 0.;
	b[4] = 0.;
	b[5] = 0.;
    } else if (myrow == 0 && mycol == 1) {
	aa[1] = a;
	aa[2] = a;
	aa[3] = -a;
	aa[4] = -a;
	aa[5] = -a;
	aa[mxllda + 1] = l;
	aa[mxllda + 2] = l;
	aa[mxllda + 3] = -l;
	aa[mxllda + 4] = -l;
	aa[mxllda + 5] = -l;
	aa[(mxllda << 1) + 1] = k;
	aa[(mxllda << 1) + 2] = k;
	aa[(mxllda << 1) + 3] = k;
	aa[(mxllda << 1) + 4] = k;
	aa[(mxllda << 1) + 5] = k;
    } else if (myrow == 0 && mycol == 2) {
	aa[1] = a;
	aa[2] = a;
	aa[3] = a;
	aa[4] = -a;
	aa[5] = -a;
	aa[mxllda + 1] = p;
	aa[mxllda + 2] = p;
	aa[mxllda + 3] = p;
	aa[mxllda + 4] = p;
	aa[mxllda + 5] = -p;
    } else if (myrow == 1 && mycol == 0) {
	aa[1] = -s;
	aa[2] = -s;
	aa[3] = -s;
	aa[4] = -s;
	aa[mxllda + 1] = -c__;
	aa[mxllda + 2] = -c__;
	aa[mxllda + 3] = -c__;
	aa[mxllda + 4] = c__;
	aa[(mxllda << 1) + 1] = a;
	aa[(mxllda << 1) + 2] = a;
	aa[(mxllda << 1) + 3] = a;
	aa[(mxllda << 1) + 4] = -a;
	aa[mxllda * 3 + 1] = c__;
	aa[mxllda * 3 + 2] = c__;
	aa[mxllda * 3 + 3] = c__;
	aa[mxllda * 3 + 4] = c__;
	b[1] = 1.;
	b[2] = 0.;
	b[3] = 0.;
	b[4] = 0.;
    } else if (myrow == 1 && mycol == 1) {
	aa[1] = a;
	aa[2] = -a;
	aa[3] = -a;
	aa[4] = -a;
	aa[mxllda + 1] = l;
	aa[mxllda + 2] = l;
	aa[mxllda + 3] = -l;
	aa[mxllda + 4] = -l;
	aa[(mxllda << 1) + 1] = k;
	aa[(mxllda << 1) + 2] = k;
	aa[(mxllda << 1) + 3] = k;
	aa[(mxllda << 1) + 4] = k;
    } else if (myrow == 1 && mycol == 2) {
	aa[1] = a;
	aa[2] = a;
	aa[3] = -a;
	aa[4] = -a;
	aa[mxllda + 1] = p;
	aa[mxllda + 2] = p;
	aa[mxllda + 3] = -p;
	aa[mxllda + 4] = -p;
    }
    return 0;
} /* matinit_ */

/* Subroutine */ int sl_init__(integer *ictxt, integer *nprow, integer *npcol)
{
    extern /* Subroutine */ int blacs_get__(integer *, integer *, integer *);
    static integer nprocs;
    extern /* Subroutine */ int blacs_gridinit__(integer *, char *, integer *,
	     integer *, ftnlen);
    static integer iam;
    extern /* Subroutine */ int blacs_pinfo__(integer *, integer *), 
	    blacs_setup__(integer *, integer *);


/*     .. Scalar Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SL_INIT initializes an NPROW x NPCOL process grid using a row-major */
/*  ordering  of  the  processes. This routine retrieves a default system */
/*  context  which  will  include all available processes. In addition it */
/*  spawns the processes if needed. */

/*  Arguments */
/*  ========= */

/*  ICTXT   (global output) INTEGER */
/*          ICTXT specifies the BLACS context handle identifying the */
/*          created process grid.  The context itself is global. */

/*  NPROW   (global input) INTEGER */
/*          NPROW specifies the number of process rows in the grid */
/*          to be created. */

/*  NPCOL   (global input) INTEGER */
/*          NPCOL specifies the number of process columns in the grid */
/*          to be created. */

/*  ===================================================================== */

/*     .. Local Scalars .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Get starting information */

    blacs_pinfo__(&iam, &nprocs);

/*     If machine needs additional set up, do it now */

    if (nprocs < 1) {
	if (iam == 0) {
	    nprocs = *nprow * *npcol;
	}
	blacs_setup__(&iam, &nprocs);
    }

/*     Define process grid */

    blacs_get__(&c_n1, &c__0, ictxt);
    blacs_gridinit__(ictxt, "Row-major", nprow, npcol, (ftnlen)9);

    return 0;

/*     End of SL_INIT */

} /* sl_init__ */

/* Main program alias */ int example1_ () { MAIN__ (); return 0; }
#ifdef __cplusplus
	}
#endif
