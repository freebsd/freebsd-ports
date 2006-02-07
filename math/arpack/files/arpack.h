extern int caxpy_(integer *n, complex *ca, complex *cx, integer *incx, complex *cy, integer *incy);
extern int ccopy_(integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
extern C_f cdotc_(complex * ret_val, integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
extern C_f cdotu_(complex * ret_val, integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
extern int cgbmv_(char *trans, integer *m, integer *n, integer *kl, integer *ku, complex *alpha, complex *a, integer *lda, complex *x, integer *incx, complex *beta, complex *y, integer *incy, ftnlen trans_len);
extern int cgbtf2_(integer *m, integer *n, integer *kl, integer *ku, complex *ab, integer *ldab, integer *ipiv, integer *info);
extern int cgbtrf_(integer *m, integer *n, integer *kl, integer *ku, complex *ab, integer *ldab, integer *ipiv, integer *info);
extern int cgbtrs_(char *trans, integer *n, integer *kl, integer *ku, integer *nrhs, complex *ab, integer *ldab, integer *ipiv, complex *b, integer *ldb, integer *info, ftnlen trans_len);
extern int cgemm_(char *transa, char *transb, integer *m, integer *n, integer *k, complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, complex *beta, complex *c__, integer *ldc, ftnlen transa_len, ftnlen transb_len);
extern int cgemv_(char *trans, integer *m, integer *n, complex *alpha, complex *a, integer *lda, complex *x, integer *incx, complex *beta, complex *y, integer *incy, ftnlen trans_len);
extern int cgeqr2_(integer *m, integer *n, complex *a, integer *lda, complex *tau, complex *work, integer *info);
extern int cgerc_(integer *m, integer *n, complex *alpha, complex *x, integer *incx, complex *y, integer *incy, complex *a, integer *lda);
extern int cgeru_(integer *m, integer *n, complex *alpha, complex *x, integer *incx, complex *y, integer *incy, complex *a, integer *lda);
extern int cgetv0_(integer *ido, char *bmat, integer *itry, logical *initv, integer *n, integer *j, complex *v, integer *ldv, complex *resid, real *rnorm, integer *ipntr, complex *workd, integer *ierr, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int cgttrf_(integer *n, complex *dl, complex *d__, complex *du, complex *du2, integer *ipiv, integer *info);
extern int cgttrs_(char *trans, integer *n, integer *nrhs, complex *dl, complex *d__, complex *du, complex *du2, integer *ipiv, complex *b, integer *ldb, integer *info, ftnlen trans_len);
extern int clacgv_(integer *n, complex *x, integer *incx);
extern int clacon_(integer *n, complex *v, complex *x, real *est, integer *kase);
extern int clacpy_(char *uplo, integer *m, integer *n, complex *a, integer *lda, complex *b, integer *ldb, ftnlen uplo_len);
extern C_f cladiv_(complex * ret_val, complex *x, complex *y);
extern int clahqr_(logical *wantt, logical *wantz, integer *n, integer *ilo, integer *ihi, complex *h__, integer *ldh, complex *w, integer *iloz, integer *ihiz, complex *z__, integer *ldz, integer *info);
extern E_f clange_(char *norm, integer *m, integer *n, complex *a, integer *lda, real *work, ftnlen norm_len);
extern E_f clanhs_(char *norm, integer *n, complex *a, integer *lda, real *work, ftnlen norm_len);
extern int clarf_(char *side, integer *m, integer *n, complex *v, integer *incv, complex *tau, complex *c__, integer *ldc, complex *work, ftnlen side_len);
extern int clarfg_(integer *n, complex *alpha, complex *x, integer *incx, complex *tau);
extern int clarnv_(integer *idist, integer *iseed, integer *n, complex *x);
extern int clartg_(complex *f, complex *g, real *cs, complex *sn, complex *r__);
extern int clascl_(char *type__, integer *kl, integer *ku, real *cfrom, real *cto, integer *m, integer *n, complex *a, integer *lda, integer *info, ftnlen type_len);
extern int claset_(char *uplo, integer *m, integer *n, complex *alpha, complex *beta, complex *a, integer *lda, ftnlen uplo_len);
extern int classq_(integer *n, complex *x, integer *incx, real *scale, real *sumsq);
extern int claswp_(integer *n, complex *a, integer *lda, integer *k1, integer *k2, integer *ipiv, integer *incx);
extern int clatrs_(char *uplo, char *trans, char *diag, char *normin, integer *n, complex *a, integer *lda, complex *x, real *scale, real *cnorm, integer *info, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len, ftnlen normin_len);
extern E_f cmach_(integer *job);
extern int cnaitr_(integer *ido, char *bmat, integer *n, integer *k, integer *np, integer *nb, complex *resid, real *rnorm, complex *v, integer *ldv, complex *h__, integer *ldh, integer *ipntr, complex *workd, integer *info, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int cnapps_(integer *n, integer *kev, integer *np, complex *shift, complex *v, integer *ldv, complex *h__, integer *ldh, complex *resid, complex *q, integer *ldq, complex *workl, complex *workd);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int cnaup2_(integer *ido, char *bmat, integer *n, char *which, integer *nev, integer *np, real *tol, complex *resid, integer *mode, integer *iupd, integer *ishift, integer *mxiter, complex *v, integer *ldv, complex *h__, integer *ldh, complex *ritz, complex *bounds, complex *q, integer *ldq, complex *workl, integer *ipntr, complex *workd, real *rwork, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int cnaupd_(integer *ido, char *bmat, integer *n, char *which, integer *nev, real *tol, complex *resid, integer *ncv, complex *v, integer *ldv, integer *iparam, integer *ipntr, complex *workd, complex *workl, integer *lworkl, real *rwork, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int cneigh_(real *rnorm, integer *n, complex *h__, integer *ldh, complex *ritz, complex *bounds, complex *q, integer *ldq, complex *workl, real *rwork, integer *ierr);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int cneupd_(logical *rvec, char *howmny, logical *select, complex *d__, complex *z__, integer *ldz, complex *sigma, complex *workev, char *bmat, integer *n, char *which, integer *nev, real *tol, complex *resid, integer *ncv, complex *v, integer *ldv, integer *iparam, integer *ipntr, complex *workd, complex *workl, integer *lworkl, real *rwork, integer *info, ftnlen howmny_len, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int cngets_(integer *ishift, char *which, integer *kev, integer *np, complex *ritz, complex *bounds, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int crot_(integer *n, complex *cx, integer *incx, complex *cy, integer *incy, real *c__, complex *s);
extern int cscal_(integer *n, complex *ca, complex *cx, integer *incx);
extern int csortc_(char *which, logical *apply, integer *n, complex *x, complex *y, ftnlen which_len);
extern int csscal_(integer *n, real *sa, complex *cx, integer *incx);
extern int cstatn_();
/* comlen timing_ 124 */
extern int cswap_(integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
extern int ctbsv_(char *uplo, char *trans, char *diag, integer *n, integer *k, complex *a, integer *lda, complex *x, integer *incx, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len);
extern int ctrevc_(char *side, char *howmny, logical *select, integer *n, complex *t, integer *ldt, complex *vl, integer *ldvl, complex *vr, integer *ldvr, integer *mm, integer *m, complex *work, real *rwork, integer *info, ftnlen side_len, ftnlen howmny_len);
extern int ctrexc_(char *compq, integer *n, complex *t, integer *ldt, complex *q, integer *ldq, integer *ifst, integer *ilst, integer *info, ftnlen compq_len);
extern int ctrmm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int ctrsen_(char *job, char *compq, logical *select, integer *n, complex *t, integer *ldt, complex *q, integer *ldq, complex *w, integer *m, real *s, real *sep, complex *work, integer *lwork, integer *info, ftnlen job_len, ftnlen compq_len);
extern int ctrsm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, complex *alpha, complex *a, integer *lda, complex *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int ctrsv_(char *uplo, char *trans, char *diag, integer *n, complex *a, integer *lda, complex *x, integer *incx, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len);
extern int ctrsyl_(char *trana, char *tranb, integer *isgn, integer *m, integer *n, complex *a, integer *lda, complex *b, integer *ldb, complex *c__, integer *ldc, real *scale, integer *info, ftnlen trana_len, ftnlen tranb_len);
extern int cunm2r_(char *side, char *trans, integer *m, integer *n, integer *k, complex *a, integer *lda, complex *tau, complex *c__, integer *ldc, complex *work, integer *info, ftnlen side_len, ftnlen trans_len);
extern doublereal dasum_(integer *n, doublereal *dx, integer *incx);
extern int daxpy_(integer *n, doublereal *da, doublereal *dx, integer *incx, doublereal *dy, integer *incy);
extern int dcopy_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy);
extern doublereal ddot_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy);
extern int dgbmv_(char *trans, integer *m, integer *n, integer *kl, integer *ku, doublereal *alpha, doublereal *a, integer *lda, doublereal *x, integer *incx, doublereal *beta, doublereal *y, integer *incy, ftnlen trans_len);
extern int dgbtf2_(integer *m, integer *n, integer *kl, integer *ku, doublereal *ab, integer *ldab, integer *ipiv, integer *info);
extern int dgbtrf_(integer *m, integer *n, integer *kl, integer *ku, doublereal *ab, integer *ldab, integer *ipiv, integer *info);
extern int dgbtrs_(char *trans, integer *n, integer *kl, integer *ku, integer *nrhs, doublereal *ab, integer *ldab, integer *ipiv, doublereal *b, integer *ldb, integer *info, ftnlen trans_len);
extern int dgemm_(char *transa, char *transb, integer *m, integer *n, integer *k, doublereal *alpha, doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *beta, doublereal *c__, integer *ldc, ftnlen transa_len, ftnlen transb_len);
extern int dgemv_(char *trans, integer *m, integer *n, doublereal *alpha, doublereal *a, integer *lda, doublereal *x, integer *incx, doublereal *beta, doublereal *y, integer *incy, ftnlen trans_len);
extern int dgeqr2_(integer *m, integer *n, doublereal *a, integer *lda, doublereal *tau, doublereal *work, integer *info);
extern int dger_(integer *m, integer *n, doublereal *alpha, doublereal *x, integer *incx, doublereal *y, integer *incy, doublereal *a, integer *lda);
extern int dgetv0_(integer *ido, char *bmat, integer *itry, logical *initv, integer *n, integer *j, doublereal *v, integer *ldv, doublereal *resid, doublereal *rnorm, integer *ipntr, doublereal *workd, integer *ierr, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dgttrf_(integer *n, doublereal *dl, doublereal *d__, doublereal *du, doublereal *du2, integer *ipiv, integer *info);
extern int dgttrs_(char *trans, integer *n, integer *nrhs, doublereal *dl, doublereal *d__, doublereal *du, doublereal *du2, integer *ipiv, doublereal *b, integer *ldb, integer *info, ftnlen trans_len);
extern int dlabad_(doublereal *small, doublereal *large);
extern int dlacon_(integer *n, doublereal *v, doublereal *x, integer *isgn, doublereal *est, integer *kase);
extern int dlacpy_(char *uplo, integer *m, integer *n, doublereal *a, integer *lda, doublereal *b, integer *ldb, ftnlen uplo_len);
extern int dladiv_(doublereal *a, doublereal *b, doublereal *c__, doublereal *d__, doublereal *p, doublereal *q);
extern int dlae2_(doublereal *a, doublereal *b, doublereal *c__, doublereal *rt1, doublereal *rt2);
extern int dlaev2_(doublereal *a, doublereal *b, doublereal *c__, doublereal *rt1, doublereal *rt2, doublereal *cs1, doublereal *sn1);
extern int dlaexc_(logical *wantq, integer *n, doublereal *t, integer *ldt, doublereal *q, integer *ldq, integer *j1, integer *n1, integer *n2, doublereal *work, integer *info);
extern int dlagtm_(char *trans, integer *n, integer *nrhs, doublereal *alpha, doublereal *dl, doublereal *d__, doublereal *du, doublereal *x, integer *ldx, doublereal *beta, doublereal *b, integer *ldb, ftnlen trans_len);
extern int dlahqr_(logical *wantt, logical *wantz, integer *n, integer *ilo, integer *ihi, doublereal *h__, integer *ldh, doublereal *wr, doublereal *wi, integer *iloz, integer *ihiz, doublereal *z__, integer *ldz, integer *info);
extern int dlaln2_(logical *ltrans, integer *na, integer *nw, doublereal *smin, doublereal *ca, doublereal *a, integer *lda, doublereal *d1, doublereal *d2, doublereal *b, integer *ldb, doublereal *wr, doublereal *wi, doublereal *x, integer *ldx, doublereal *scale, doublereal *xnorm, integer *info);
extern doublereal dlamch_(char *cmach, ftnlen cmach_len);
extern int dlamc1_(integer *beta, integer *t, logical *rnd, logical *ieee1);
extern int dlamc2_(integer *beta, integer *t, logical *rnd, doublereal *eps, integer *emin, doublereal *rmin, integer *emax, doublereal *rmax);
extern doublereal dlamc3_(doublereal *a, doublereal *b);
extern int dlamc4_(integer *emin, doublereal *start, integer *base);
extern int dlamc5_(integer *beta, integer *p, integer *emin, logical *ieee, integer *emax, doublereal *rmax);
extern doublereal dlange_(char *norm, integer *m, integer *n, doublereal *a, integer *lda, doublereal *work, ftnlen norm_len);
extern doublereal dlanhs_(char *norm, integer *n, doublereal *a, integer *lda, doublereal *work, ftnlen norm_len);
extern doublereal dlanst_(char *norm, integer *n, doublereal *d__, doublereal *e, ftnlen norm_len);
extern int dlanv2_(doublereal *a, doublereal *b, doublereal *c__, doublereal *d__, doublereal *rt1r, doublereal *rt1i, doublereal *rt2r, doublereal *rt2i, doublereal *cs, doublereal *sn);
extern int dlaptm_(integer *n, integer *nrhs, doublereal *alpha, doublereal *d__, doublereal *e, doublereal *x, integer *ldx, doublereal *beta, doublereal *b, integer *ldb);
extern doublereal dlapy2_(doublereal *x, doublereal *y);
extern doublereal dlapy3_(doublereal *x, doublereal *y, doublereal *z__);
extern int dlaqrb_(logical *wantt, integer *n, integer *ilo, integer *ihi, doublereal *h__, integer *ldh, doublereal *wr, doublereal *wi, doublereal *z__, integer *info);
extern doublereal dlaran_(integer *iseed);
extern int dlarf_(char *side, integer *m, integer *n, doublereal *v, integer *incv, doublereal *tau, doublereal *c__, integer *ldc, doublereal *work, ftnlen side_len);
extern int dlarfg_(integer *n, doublereal *alpha, doublereal *x, integer *incx, doublereal *tau);
extern int dlarfx_(char *side, integer *m, integer *n, doublereal *v, doublereal *tau, doublereal *c__, integer *ldc, doublereal *work, ftnlen side_len);
extern doublereal dlarnd_(integer *idist, integer *iseed);
extern int dlarnv_(integer *idist, integer *iseed, integer *n, doublereal *x);
extern int dlartg_(doublereal *f, doublereal *g, doublereal *cs, doublereal *sn, doublereal *r__);
extern int dlaruv_(integer *iseed, integer *n, doublereal *x);
extern int dlascl_(char *type__, integer *kl, integer *ku, doublereal *cfrom, doublereal *cto, integer *m, integer *n, doublereal *a, integer *lda, integer *info, ftnlen type_len);
extern int dlaset_(char *uplo, integer *m, integer *n, doublereal *alpha, doublereal *beta, doublereal *a, integer *lda, ftnlen uplo_len);
extern int dlasr_(char *side, char *pivot, char *direct, integer *m, integer *n, doublereal *c__, doublereal *s, doublereal *a, integer *lda, ftnlen side_len, ftnlen pivot_len, ftnlen direct_len);
extern int dlasrt_(char *id, integer *n, doublereal *d__, integer *info, ftnlen id_len);
extern int dlassq_(integer *n, doublereal *x, integer *incx, doublereal *scale, doublereal *sumsq);
extern int dlaswp_(integer *n, doublereal *a, integer *lda, integer *k1, integer *k2, integer *ipiv, integer *incx);
extern int dlasy2_(logical *ltranl, logical *ltranr, integer *isgn, integer *n1, integer *n2, doublereal *tl, integer *ldtl, doublereal *tr, integer *ldtr, doublereal *b, integer *ldb, doublereal *scale, doublereal *x, integer *ldx, doublereal *xnorm, integer *info);
extern int dnaitr_(integer *ido, char *bmat, integer *n, integer *k, integer *np, integer *nb, doublereal *resid, doublereal *rnorm, doublereal *v, integer *ldv, doublereal *h__, integer *ldh, integer *ipntr, doublereal *workd, integer *info, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dnapps_(integer *n, integer *kev, integer *np, doublereal *shiftr, doublereal *shifti, doublereal *v, integer *ldv, doublereal *h__, integer *ldh, doublereal *resid, doublereal *q, integer *ldq, doublereal *workl, doublereal *workd);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dnaup2_(integer *ido, char *bmat, integer *n, char *which, integer *nev, integer *np, doublereal *tol, doublereal *resid, integer *mode, integer *iupd, integer *ishift, integer *mxiter, doublereal *v, integer *ldv, doublereal *h__, integer *ldh, doublereal *ritzr, doublereal *ritzi, doublereal *bounds, doublereal *q, integer *ldq, doublereal *workl, integer *ipntr, doublereal *workd, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dnaupd_(integer *ido, char *bmat, integer *n, char *which, integer *nev, doublereal *tol, doublereal *resid, integer *ncv, doublereal *v, integer *ldv, integer *iparam, integer *ipntr, doublereal *workd, doublereal *workl, integer *lworkl, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dnconv_(integer *n, doublereal *ritzr, doublereal *ritzi, doublereal *bounds, doublereal *tol, integer *nconv);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dneigh_(doublereal *rnorm, integer *n, doublereal *h__, integer *ldh, doublereal *ritzr, doublereal *ritzi, doublereal *bounds, doublereal *q, integer *ldq, doublereal *workl, integer *ierr);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dneupd_(logical *rvec, char *howmny, logical *select, doublereal *dr, doublereal *di, doublereal *z__, integer *ldz, doublereal *sigmar, doublereal *sigmai, doublereal *workev, char *bmat, integer *n, char *which, integer *nev, doublereal *tol, doublereal *resid, integer *ncv, doublereal *v, integer *ldv, integer *iparam, integer *ipntr, doublereal *workd, doublereal *workl, integer *lworkl, integer *info, ftnlen howmny_len, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dngets_(integer *ishift, char *which, integer *kev, integer *np, doublereal *ritzr, doublereal *ritzi, doublereal *bounds, doublereal *shiftr, doublereal *shifti, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern doublereal dnrm2_(integer *n, doublereal *dx, integer *incx);
extern int dorm2r_(char *side, char *trans, integer *m, integer *n, integer *k, doublereal *a, integer *lda, doublereal *tau, doublereal *c__, integer *ldc, doublereal *work, integer *info, ftnlen side_len, ftnlen trans_len);
extern int dpttrf_(integer *n, doublereal *d__, doublereal *e, integer *info);
extern int dpttrs_(integer *n, integer *nrhs, doublereal *d__, doublereal *e, doublereal *b, integer *ldb, integer *info);
extern int drot_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy, doublereal *c__, doublereal *s);
extern int drotg_(doublereal *da, doublereal *db, doublereal *c__, doublereal *s);
extern int dsaitr_(integer *ido, char *bmat, integer *n, integer *k, integer *np, integer *mode, doublereal *resid, doublereal *rnorm, doublereal *v, integer *ldv, doublereal *h__, integer *ldh, integer *ipntr, doublereal *workd, integer *info, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dsapps_(integer *n, integer *kev, integer *np, doublereal *shift, doublereal *v, integer *ldv, doublereal *h__, integer *ldh, doublereal *resid, doublereal *q, integer *ldq, doublereal *workd);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dsaup2_(integer *ido, char *bmat, integer *n, char *which, integer *nev, integer *np, doublereal *tol, doublereal *resid, integer *mode, integer *iupd, integer *ishift, integer *mxiter, doublereal *v, integer *ldv, doublereal *h__, integer *ldh, doublereal *ritz, doublereal *bounds, doublereal *q, integer *ldq, doublereal *workl, integer *ipntr, doublereal *workd, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dsaupd_(integer *ido, char *bmat, integer *n, char *which, integer *nev, doublereal *tol, doublereal *resid, integer *ncv, doublereal *v, integer *ldv, integer *iparam, integer *ipntr, doublereal *workd, doublereal *workl, integer *lworkl, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dscal_(integer *n, doublereal *da, doublereal *dx, integer *incx);
extern int dsconv_(integer *n, doublereal *ritz, doublereal *bounds, doublereal *tol, integer *nconv);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dseigt_(doublereal *rnorm, integer *n, doublereal *h__, integer *ldh, doublereal *eig, doublereal *bounds, doublereal *workl, integer *ierr);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dsesrt_(char *which, logical *apply, integer *n, doublereal *x, integer *na, doublereal *a, integer *lda, ftnlen which_len);
extern int dseupd_(logical *rvec, char *howmny, logical *select, doublereal *d__, doublereal *z__, integer *ldz, doublereal *sigma, char *bmat, integer *n, char *which, integer *nev, doublereal *tol, doublereal *resid, integer *ncv, doublereal *v, integer *ldv, integer *iparam, integer *ipntr, doublereal *workd, doublereal *workl, integer *lworkl, integer *info, ftnlen howmny_len, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dsgets_(integer *ishift, char *which, integer *kev, integer *np, doublereal *ritz, doublereal *bounds, doublereal *shifts, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int dsortc_(char *which, logical *apply, integer *n, doublereal *xreal, doublereal *ximag, doublereal *y, ftnlen which_len);
extern int dsortr_(char *which, logical *apply, integer *n, doublereal *x1, doublereal *x2, ftnlen which_len);
extern int dstatn_();
/* comlen timing_ 124 */
extern int dstats_();
/* comlen timing_ 124 */
extern int dsteqr_(char *compz, integer *n, doublereal *d__, doublereal *e, doublereal *z__, integer *ldz, doublereal *work, integer *info, ftnlen compz_len);
extern int dstqrb_(integer *n, doublereal *d__, doublereal *e, doublereal *z__, doublereal *work, integer *info);
extern int dswap_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy);
extern int dsymv_(char *uplo, integer *n, doublereal *alpha, doublereal *a, integer *lda, doublereal *x, integer *incx, doublereal *beta, doublereal *y, integer *incy, ftnlen uplo_len);
extern int dsyr2_(char *uplo, integer *n, doublereal *alpha, doublereal *x, integer *incx, doublereal *y, integer *incy, doublereal *a, integer *lda, ftnlen uplo_len);
extern int dtbsv_(char *uplo, char *trans, char *diag, integer *n, integer *k, doublereal *a, integer *lda, doublereal *x, integer *incx, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len);
extern int dtrevc_(char *side, char *howmny, logical *select, integer *n, doublereal *t, integer *ldt, doublereal *vl, integer *ldvl, doublereal *vr, integer *ldvr, integer *mm, integer *m, doublereal *work, integer *info, ftnlen side_len, ftnlen howmny_len);
extern int dtrexc_(char *compq, integer *n, doublereal *t, integer *ldt, doublereal *q, integer *ldq, integer *ifst, integer *ilst, doublereal *work, integer *info, ftnlen compq_len);
extern int dtrmm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, doublereal *alpha, doublereal *a, integer *lda, doublereal *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int dtrsen_(char *job, char *compq, logical *select, integer *n, doublereal *t, integer *ldt, doublereal *q, integer *ldq, doublereal *wr, doublereal *wi, integer *m, doublereal *s, doublereal *sep, doublereal *work, integer *lwork, integer *iwork, integer *liwork, integer *info, ftnlen job_len, ftnlen compq_len);
extern int dtrsm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, doublereal *alpha, doublereal *a, integer *lda, doublereal *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int dtrsyl_(char *trana, char *tranb, integer *isgn, integer *m, integer *n, doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *c__, integer *ldc, doublereal *scale, integer *info, ftnlen trana_len, ftnlen tranb_len);
extern doublereal dzasum_(integer *n, doublecomplex *zx, integer *incx);
extern doublereal dznrm2_(integer *n, doublecomplex *x, integer *incx);
extern doublereal dzsum1_(integer *n, doublecomplex *cx, integer *incx);
extern integer icamax_(integer *n, complex *cx, integer *incx);
extern integer icmax1_(integer *n, complex *cx, integer *incx);
extern integer idamax_(integer *n, doublereal *dx, integer *incx);
extern integer ilaenv_(integer *ispec, char *name__, char *opts, integer *n1, integer *n2, integer *n3, integer *n4, ftnlen name_len, ftnlen opts_len);
extern integer isamax_(integer *n, real *sx, integer *incx);
extern integer izamax_(integer *n, doublecomplex *zx, integer *incx);
extern doublereal dcabs1_(doublecomplex *z__);
extern integer izmax1_(integer *n, doublecomplex *cx, integer *incx);
extern logical lsame_(char *ca, char *cb, ftnlen ca_len, ftnlen cb_len);
extern logical lsamen_(integer *n, char *ca, char *cb, ftnlen ca_len, ftnlen cb_len);
extern E_f sasum_(integer *n, real *sx, integer *incx);
extern int saxpy_(integer *n, real *sa, real *sx, integer *incx, real *sy, integer *incy);
extern E_f scasum_(integer *n, complex *cx, integer *incx);
extern E_f scnrm2_(integer *n, complex *x, integer *incx);
extern int scopy_(integer *n, real *sx, integer *incx, real *sy, integer *incy);
extern E_f scsum1_(integer *n, complex *cx, integer *incx);
extern E_f sdot_(integer *n, real *sx, integer *incx, real *sy, integer *incy);
extern int sgbmv_(char *trans, integer *m, integer *n, integer *kl, integer *ku, real *alpha, real *a, integer *lda, real *x, integer *incx, real *beta, real *y, integer *incy, ftnlen trans_len);
extern int sgbtf2_(integer *m, integer *n, integer *kl, integer *ku, real *ab, integer *ldab, integer *ipiv, integer *info);
extern int sgbtrf_(integer *m, integer *n, integer *kl, integer *ku, real *ab, integer *ldab, integer *ipiv, integer *info);
extern int sgbtrs_(char *trans, integer *n, integer *kl, integer *ku, integer *nrhs, real *ab, integer *ldab, integer *ipiv, real *b, integer *ldb, integer *info, ftnlen trans_len);
extern int sgemm_(char *transa, char *transb, integer *m, integer *n, integer *k, real *alpha, real *a, integer *lda, real *b, integer *ldb, real *beta, real *c__, integer *ldc, ftnlen transa_len, ftnlen transb_len);
extern int sgemv_(char *trans, integer *m, integer *n, real *alpha, real *a, integer *lda, real *x, integer *incx, real *beta, real *y, integer *incy, ftnlen trans_len);
extern int sgeqr2_(integer *m, integer *n, real *a, integer *lda, real *tau, real *work, integer *info);
extern int sger_(integer *m, integer *n, real *alpha, real *x, integer *incx, real *y, integer *incy, real *a, integer *lda);
extern int sgetv0_(integer *ido, char *bmat, integer *itry, logical *initv, integer *n, integer *j, real *v, integer *ldv, real *resid, real *rnorm, integer *ipntr, real *workd, integer *ierr, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int sgttrf_(integer *n, real *dl, real *d__, real *du, real *du2, integer *ipiv, integer *info);
extern int sgttrs_(char *trans, integer *n, integer *nrhs, real *dl, real *d__, real *du, real *du2, integer *ipiv, real *b, integer *ldb, integer *info, ftnlen trans_len);
extern int slabad_(real *small, real *large);
extern int slacon_(integer *n, real *v, real *x, integer *isgn, real *est, integer *kase);
extern int slacpy_(char *uplo, integer *m, integer *n, real *a, integer *lda, real *b, integer *ldb, ftnlen uplo_len);
extern int sladiv_(real *a, real *b, real *c__, real *d__, real *p, real *q);
extern int slae2_(real *a, real *b, real *c__, real *rt1, real *rt2);
extern int slaev2_(real *a, real *b, real *c__, real *rt1, real *rt2, real *cs1, real *sn1);
extern int slaexc_(logical *wantq, integer *n, real *t, integer *ldt, real *q, integer *ldq, integer *j1, integer *n1, integer *n2, real *work, integer *info);
extern int slagtm_(char *trans, integer *n, integer *nrhs, real *alpha, real *dl, real *d__, real *du, real *x, integer *ldx, real *beta, real *b, integer *ldb, ftnlen trans_len);
extern int slahqr_(logical *wantt, logical *wantz, integer *n, integer *ilo, integer *ihi, real *h__, integer *ldh, real *wr, real *wi, integer *iloz, integer *ihiz, real *z__, integer *ldz, integer *info);
extern int slaln2_(logical *ltrans, integer *na, integer *nw, real *smin, real *ca, real *a, integer *lda, real *d1, real *d2, real *b, integer *ldb, real *wr, real *wi, real *x, integer *ldx, real *scale, real *xnorm, integer *info);
extern E_f slamch_(char *cmach, ftnlen cmach_len);
extern int slamc1_(integer *beta, integer *t, logical *rnd, logical *ieee1);
extern int slamc2_(integer *beta, integer *t, logical *rnd, real *eps, integer *emin, real *rmin, integer *emax, real *rmax);
extern E_f slamc3_(real *a, real *b);
extern int slamc4_(integer *emin, real *start, integer *base);
extern int slamc5_(integer *beta, integer *p, integer *emin, logical *ieee, integer *emax, real *rmax);
extern E_f slange_(char *norm, integer *m, integer *n, real *a, integer *lda, real *work, ftnlen norm_len);
extern E_f slanhs_(char *norm, integer *n, real *a, integer *lda, real *work, ftnlen norm_len);
extern E_f slanst_(char *norm, integer *n, real *d__, real *e, ftnlen norm_len);
extern int slanv2_(real *a, real *b, real *c__, real *d__, real *rt1r, real *rt1i, real *rt2r, real *rt2i, real *cs, real *sn);
extern int slaptm_(integer *n, integer *nrhs, real *alpha, real *d__, real *e, real *x, integer *ldx, real *beta, real *b, integer *ldb);
extern E_f slapy2_(real *x, real *y);
extern E_f slapy3_(real *x, real *y, real *z__);
extern int slaqrb_(logical *wantt, integer *n, integer *ilo, integer *ihi, real *h__, integer *ldh, real *wr, real *wi, real *z__, integer *info);
extern E_f slaran_(integer *iseed);
extern int slarf_(char *side, integer *m, integer *n, real *v, integer *incv, real *tau, real *c__, integer *ldc, real *work, ftnlen side_len);
extern int slarfg_(integer *n, real *alpha, real *x, integer *incx, real *tau);
extern int slarfx_(char *side, integer *m, integer *n, real *v, real *tau, real *c__, integer *ldc, real *work, ftnlen side_len);
extern E_f slarnd_(integer *idist, integer *iseed);
extern int slarnv_(integer *idist, integer *iseed, integer *n, real *x);
extern int slartg_(real *f, real *g, real *cs, real *sn, real *r__);
extern int slaruv_(integer *iseed, integer *n, real *x);
extern int slascl_(char *type__, integer *kl, integer *ku, real *cfrom, real *cto, integer *m, integer *n, real *a, integer *lda, integer *info, ftnlen type_len);
extern int slaset_(char *uplo, integer *m, integer *n, real *alpha, real *beta, real *a, integer *lda, ftnlen uplo_len);
extern int slasr_(char *side, char *pivot, char *direct, integer *m, integer *n, real *c__, real *s, real *a, integer *lda, ftnlen side_len, ftnlen pivot_len, ftnlen direct_len);
extern int slasrt_(char *id, integer *n, real *d__, integer *info, ftnlen id_len);
extern int slassq_(integer *n, real *x, integer *incx, real *scale, real *sumsq);
extern int slaswp_(integer *n, real *a, integer *lda, integer *k1, integer *k2, integer *ipiv, integer *incx);
extern int slasy2_(logical *ltranl, logical *ltranr, integer *isgn, integer *n1, integer *n2, real *tl, integer *ldtl, real *tr, integer *ldtr, real *b, integer *ldb, real *scale, real *x, integer *ldx, real *xnorm, integer *info);
extern int snaitr_(integer *ido, char *bmat, integer *n, integer *k, integer *np, integer *nb, real *resid, real *rnorm, real *v, integer *ldv, real *h__, integer *ldh, integer *ipntr, real *workd, integer *info, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int snapps_(integer *n, integer *kev, integer *np, real *shiftr, real *shifti, real *v, integer *ldv, real *h__, integer *ldh, real *resid, real *q, integer *ldq, real *workl, real *workd);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int snaup2_(integer *ido, char *bmat, integer *n, char *which, integer *nev, integer *np, real *tol, real *resid, integer *mode, integer *iupd, integer *ishift, integer *mxiter, real *v, integer *ldv, real *h__, integer *ldh, real *ritzr, real *ritzi, real *bounds, real *q, integer *ldq, real *workl, integer *ipntr, real *workd, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int snaupd_(integer *ido, char *bmat, integer *n, char *which, integer *nev, real *tol, real *resid, integer *ncv, real *v, integer *ldv, integer *iparam, integer *ipntr, real *workd, real *workl, integer *lworkl, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int snconv_(integer *n, real *ritzr, real *ritzi, real *bounds, real *tol, integer *nconv);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int sneigh_(real *rnorm, integer *n, real *h__, integer *ldh, real *ritzr, real *ritzi, real *bounds, real *q, integer *ldq, real *workl, integer *ierr);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int sneupd_(logical *rvec, char *howmny, logical *select, real *dr, real *di, real *z__, integer *ldz, real *sigmar, real *sigmai, real *workev, char *bmat, integer *n, char *which, integer *nev, real *tol, real *resid, integer *ncv, real *v, integer *ldv, integer *iparam, integer *ipntr, real *workd, real *workl, integer *lworkl, integer *info, ftnlen howmny_len, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int sngets_(integer *ishift, char *which, integer *kev, integer *np, real *ritzr, real *ritzi, real *bounds, real *shiftr, real *shifti, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern E_f snrm2_(integer *n, real *sx, integer *incx);
extern int sorm2r_(char *side, char *trans, integer *m, integer *n, integer *k, real *a, integer *lda, real *tau, real *c__, integer *ldc, real *work, integer *info, ftnlen side_len, ftnlen trans_len);
extern int spttrf_(integer *n, real *d__, real *e, integer *info);
extern int spttrs_(integer *n, integer *nrhs, real *d__, real *e, real *b, integer *ldb, integer *info);
extern int srot_(integer *n, real *sx, integer *incx, real *sy, integer *incy, real *c__, real *s);
extern int srotg_(real *sa, real *sb, real *c__, real *s);
extern int ssaitr_(integer *ido, char *bmat, integer *n, integer *k, integer *np, integer *mode, real *resid, real *rnorm, real *v, integer *ldv, real *h__, integer *ldh, integer *ipntr, real *workd, integer *info, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int ssapps_(integer *n, integer *kev, integer *np, real *shift, real *v, integer *ldv, real *h__, integer *ldh, real *resid, real *q, integer *ldq, real *workd);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int ssaup2_(integer *ido, char *bmat, integer *n, char *which, integer *nev, integer *np, real *tol, real *resid, integer *mode, integer *iupd, integer *ishift, integer *mxiter, real *v, integer *ldv, real *h__, integer *ldh, real *ritz, real *bounds, real *q, integer *ldq, real *workl, integer *ipntr, real *workd, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int ssaupd_(integer *ido, char *bmat, integer *n, char *which, integer *nev, real *tol, real *resid, integer *ncv, real *v, integer *ldv, integer *iparam, integer *ipntr, real *workd, real *workl, integer *lworkl, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int sscal_(integer *n, real *sa, real *sx, integer *incx);
extern int ssconv_(integer *n, real *ritz, real *bounds, real *tol, integer *nconv);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int sseigt_(real *rnorm, integer *n, real *h__, integer *ldh, real *eig, real *bounds, real *workl, integer *ierr);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int ssesrt_(char *which, logical *apply, integer *n, real *x, integer *na, real *a, integer *lda, ftnlen which_len);
extern int sseupd_(logical *rvec, char *howmny, logical *select, real *d__, real *z__, integer *ldz, real *sigma, char *bmat, integer *n, char *which, integer *nev, real *tol, real *resid, integer *ncv, real *v, integer *ldv, integer *iparam, integer *ipntr, real *workd, real *workl, integer *lworkl, integer *info, ftnlen howmny_len, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int ssgets_(integer *ishift, char *which, integer *kev, integer *np, real *ritz, real *bounds, real *shifts, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int ssortc_(char *which, logical *apply, integer *n, real *xreal, real *ximag, real *y, ftnlen which_len);
extern int ssortr_(char *which, logical *apply, integer *n, real *x1, real *x2, ftnlen which_len);
extern int sstatn_();
/* comlen timing_ 124 */
extern int sstats_();
/* comlen timing_ 124 */
extern int ssteqr_(char *compz, integer *n, real *d__, real *e, real *z__, integer *ldz, real *work, integer *info, ftnlen compz_len);
extern int sstqrb_(integer *n, real *d__, real *e, real *z__, real *work, integer *info);
extern int sswap_(integer *n, real *sx, integer *incx, real *sy, integer *incy);
extern int ssymv_(char *uplo, integer *n, real *alpha, real *a, integer *lda, real *x, integer *incx, real *beta, real *y, integer *incy, ftnlen uplo_len);
extern int ssyr2_(char *uplo, integer *n, real *alpha, real *x, integer *incx, real *y, integer *incy, real *a, integer *lda, ftnlen uplo_len);
extern int stbsv_(char *uplo, char *trans, char *diag, integer *n, integer *k, real *a, integer *lda, real *x, integer *incx, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len);
extern int strevc_(char *side, char *howmny, logical *select, integer *n, real *t, integer *ldt, real *vl, integer *ldvl, real *vr, integer *ldvr, integer *mm, integer *m, real *work, integer *info, ftnlen side_len, ftnlen howmny_len);
extern int strexc_(char *compq, integer *n, real *t, integer *ldt, real *q, integer *ldq, integer *ifst, integer *ilst, real *work, integer *info, ftnlen compq_len);
extern int strmm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, real *alpha, real *a, integer *lda, real *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int strsen_(char *job, char *compq, logical *select, integer *n, real *t, integer *ldt, real *q, integer *ldq, real *wr, real *wi, integer *m, real *s, real *sep, real *work, integer *lwork, integer *iwork, integer *liwork, integer *info, ftnlen job_len, ftnlen compq_len);
extern int strsm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, real *alpha, real *a, integer *lda, real *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int strsyl_(char *trana, char *tranb, integer *isgn, integer *m, integer *n, real *a, integer *lda, real *b, integer *ldb, real *c__, integer *ldc, real *scale, integer *info, ftnlen trana_len, ftnlen tranb_len);
extern int xerbla_(char *srname, integer *info, ftnlen srname_len);
extern int xlaenv_(integer *ispec, integer *nvalue);
/* comlen claenv_ 400 */
extern int zaxpy_(integer *n, doublecomplex *za, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);
extern int zcopy_(integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);
extern Z_f zdotc_(doublecomplex * ret_val, integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);
extern Z_f zdotu_(doublecomplex * ret_val, integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);
extern int zdscal_(integer *n, doublereal *da, doublecomplex *zx, integer *incx);
extern int zgbmv_(char *trans, integer *m, integer *n, integer *kl, integer *ku, doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *x, integer *incx, doublecomplex *beta, doublecomplex *y, integer *incy, ftnlen trans_len);
extern int zgbtf2_(integer *m, integer *n, integer *kl, integer *ku, doublecomplex *ab, integer *ldab, integer *ipiv, integer *info);
extern int zgbtrf_(integer *m, integer *n, integer *kl, integer *ku, doublecomplex *ab, integer *ldab, integer *ipiv, integer *info);
extern int zgbtrs_(char *trans, integer *n, integer *kl, integer *ku, integer *nrhs, doublecomplex *ab, integer *ldab, integer *ipiv, doublecomplex *b, integer *ldb, integer *info, ftnlen trans_len);
extern int zgemm_(char *transa, char *transb, integer *m, integer *n, integer *k, doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, doublecomplex *beta, doublecomplex *c__, integer *ldc, ftnlen transa_len, ftnlen transb_len);
extern int zgemv_(char *trans, integer *m, integer *n, doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *x, integer *incx, doublecomplex *beta, doublecomplex *y, integer *incy, ftnlen trans_len);
extern int zgeqr2_(integer *m, integer *n, doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *work, integer *info);
extern int zgerc_(integer *m, integer *n, doublecomplex *alpha, doublecomplex *x, integer *incx, doublecomplex *y, integer *incy, doublecomplex *a, integer *lda);
extern int zgeru_(integer *m, integer *n, doublecomplex *alpha, doublecomplex *x, integer *incx, doublecomplex *y, integer *incy, doublecomplex *a, integer *lda);
extern int zgetv0_(integer *ido, char *bmat, integer *itry, logical *initv, integer *n, integer *j, doublecomplex *v, integer *ldv, doublecomplex *resid, doublereal *rnorm, integer *ipntr, doublecomplex *workd, integer *ierr, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int zgttrf_(integer *n, doublecomplex *dl, doublecomplex *d__, doublecomplex *du, doublecomplex *du2, integer *ipiv, integer *info);
extern int zgttrs_(char *trans, integer *n, integer *nrhs, doublecomplex *dl, doublecomplex *d__, doublecomplex *du, doublecomplex *du2, integer *ipiv, doublecomplex *b, integer *ldb, integer *info, ftnlen trans_len);
extern int zlacgv_(integer *n, doublecomplex *x, integer *incx);
extern int zlacon_(integer *n, doublecomplex *v, doublecomplex *x, doublereal *est, integer *kase);
extern int zlacpy_(char *uplo, integer *m, integer *n, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, ftnlen uplo_len);
extern Z_f zladiv_(doublecomplex * ret_val, doublecomplex *x, doublecomplex *y);
extern int zlahqr_(logical *wantt, logical *wantz, integer *n, integer *ilo, integer *ihi, doublecomplex *h__, integer *ldh, doublecomplex *w, integer *iloz, integer *ihiz, doublecomplex *z__, integer *ldz, integer *info);
extern doublereal zlange_(char *norm, integer *m, integer *n, doublecomplex *a, integer *lda, doublereal *work, ftnlen norm_len);
extern doublereal zlanhs_(char *norm, integer *n, doublecomplex *a, integer *lda, doublereal *work, ftnlen norm_len);
extern int zlarf_(char *side, integer *m, integer *n, doublecomplex *v, integer *incv, doublecomplex *tau, doublecomplex *c__, integer *ldc, doublecomplex *work, ftnlen side_len);
extern int zlarfg_(integer *n, doublecomplex *alpha, doublecomplex *x, integer *incx, doublecomplex *tau);
extern int zlarnv_(integer *idist, integer *iseed, integer *n, doublecomplex *x);
extern int zlartg_(doublecomplex *f, doublecomplex *g, doublereal *cs, doublecomplex *sn, doublecomplex *r__);
extern int zlascl_(char *type__, integer *kl, integer *ku, doublereal *cfrom, doublereal *cto, integer *m, integer *n, doublecomplex *a, integer *lda, integer *info, ftnlen type_len);
extern int zlaset_(char *uplo, integer *m, integer *n, doublecomplex *alpha, doublecomplex *beta, doublecomplex *a, integer *lda, ftnlen uplo_len);
extern int zlassq_(integer *n, doublecomplex *x, integer *incx, doublereal *scale, doublereal *sumsq);
extern int zlaswp_(integer *n, doublecomplex *a, integer *lda, integer *k1, integer *k2, integer *ipiv, integer *incx);
extern int zlatrs_(char *uplo, char *trans, char *diag, char *normin, integer *n, doublecomplex *a, integer *lda, doublecomplex *x, doublereal *scale, doublereal *cnorm, integer *info, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len, ftnlen normin_len);
extern doublereal zmach_(integer *job);
extern int znaitr_(integer *ido, char *bmat, integer *n, integer *k, integer *np, integer *nb, doublecomplex *resid, doublereal *rnorm, doublecomplex *v, integer *ldv, doublecomplex *h__, integer *ldh, integer *ipntr, doublecomplex *workd, integer *info, ftnlen bmat_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int znapps_(integer *n, integer *kev, integer *np, doublecomplex *shift, doublecomplex *v, integer *ldv, doublecomplex *h__, integer *ldh, doublecomplex *resid, doublecomplex *q, integer *ldq, doublecomplex *workl, doublecomplex *workd);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int znaup2_(integer *ido, char *bmat, integer *n, char *which, integer *nev, integer *np, doublereal *tol, doublecomplex *resid, integer *mode, integer *iupd, integer *ishift, integer *mxiter, doublecomplex *v, integer *ldv, doublecomplex *h__, integer *ldh, doublecomplex *ritz, doublecomplex *bounds, doublecomplex *q, integer *ldq, doublecomplex *workl, integer *ipntr, doublecomplex *workd, doublereal *rwork, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int znaupd_(integer *ido, char *bmat, integer *n, char *which, integer *nev, doublereal *tol, doublecomplex *resid, integer *ncv, doublecomplex *v, integer *ldv, integer *iparam, integer *ipntr, doublecomplex *workd, doublecomplex *workl, integer *lworkl, doublereal *rwork, integer *info, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int zneigh_(doublereal *rnorm, integer *n, doublecomplex *h__, integer *ldh, doublecomplex *ritz, doublecomplex *bounds, doublecomplex *q, integer *ldq, doublecomplex *workl, doublereal *rwork, integer *ierr);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int zneupd_(logical *rvec, char *howmny, logical *select, doublecomplex *d__, doublecomplex *z__, integer *ldz, doublecomplex *sigma, doublecomplex *workev, char *bmat, integer *n, char *which, integer *nev, doublereal *tol, doublecomplex *resid, integer *ncv, doublecomplex *v, integer *ldv, integer *iparam, integer *ipntr, doublecomplex *workd, doublecomplex *workl, integer *lworkl, doublereal *rwork, integer *info, ftnlen howmny_len, ftnlen bmat_len, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int zngets_(integer *ishift, char *which, integer *kev, integer *np, doublecomplex *ritz, doublecomplex *bounds, ftnlen which_len);
/* comlen debug_ 96 */
/* comlen timing_ 124 */
extern int zrot_(integer *n, doublecomplex *cx, integer *incx, doublecomplex *cy, integer *incy, doublereal *c__, doublecomplex *s);
extern int zscal_(integer *n, doublecomplex *za, doublecomplex *zx, integer *incx);
extern int zsortc_(char *which, logical *apply, integer *n, doublecomplex *x, doublecomplex *y, ftnlen which_len);
extern int zstatn_();
/* comlen timing_ 124 */
extern int zswap_(integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);
extern int ztbsv_(char *uplo, char *trans, char *diag, integer *n, integer *k, doublecomplex *a, integer *lda, doublecomplex *x, integer *incx, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len);
extern int ztrevc_(char *side, char *howmny, logical *select, integer *n, doublecomplex *t, integer *ldt, doublecomplex *vl, integer *ldvl, doublecomplex *vr, integer *ldvr, integer *mm, integer *m, doublecomplex *work, doublereal *rwork, integer *info, ftnlen side_len, ftnlen howmny_len);
extern int ztrexc_(char *compq, integer *n, doublecomplex *t, integer *ldt, doublecomplex *q, integer *ldq, integer *ifst, integer *ilst, integer *info, ftnlen compq_len);
extern int ztrmm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int ztrsen_(char *job, char *compq, logical *select, integer *n, doublecomplex *t, integer *ldt, doublecomplex *q, integer *ldq, doublecomplex *w, integer *m, doublereal *s, doublereal *sep, doublecomplex *work, integer *lwork, integer *info, ftnlen job_len, ftnlen compq_len);
extern int ztrsm_(char *side, char *uplo, char *transa, char *diag, integer *m, integer *n, doublecomplex *alpha, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, ftnlen side_len, ftnlen uplo_len, ftnlen transa_len, ftnlen diag_len);
extern int ztrsv_(char *uplo, char *trans, char *diag, integer *n, doublecomplex *a, integer *lda, doublecomplex *x, integer *incx, ftnlen uplo_len, ftnlen trans_len, ftnlen diag_len);
extern int ztrsyl_(char *trana, char *tranb, integer *isgn, integer *m, integer *n, doublecomplex *a, integer *lda, doublecomplex *b, integer *ldb, doublecomplex *c__, integer *ldc, doublereal *scale, integer *info, ftnlen trana_len, ftnlen tranb_len);
extern int zunm2r_(char *side, char *trans, integer *m, integer *n, integer *k, doublecomplex *a, integer *lda, doublecomplex *tau, doublecomplex *c__, integer *ldc, doublecomplex *work, integer *info, ftnlen side_len, ftnlen trans_len);
