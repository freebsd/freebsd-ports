# New ports collection makefile for:    lapack
# Version required:     2.0
# Date created:         2 July 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	LAPACK
PKGNAME=	lapack-2.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/
DISTFILES=	lapack.tgz manpages.tgz

MAINTAINER=	jmz@FreeBSD.org

DIST_SUBDIR=	lapack

MANL=	cgbmv.l cgemm.l cgemv.l cgerc.l cgeru.l chbmv.l chemm.l chemv.l \
	cher.l cher2.l cher2k.l cherk.l chpmv.l chpr.l chpr2.l cscal.l \
	csymm.l csyr2k.l csyrk.l ctbmv.l ctbsv.l ctpmv.l ctpsv.l ctrmm.l \
	ctrmv.l ctrsm.l ctrsv.l dcabs1.l dgbmv.l dgemm.l dgemv.l dger.l \
	dsbmv.l dspmv.l dspr.l dspr2.l dsymm.l dsymv.l dsyr.l dsyr2.l \
	dsyr2k.l dsyrk.l dtbmv.l dtbsv.l dtpmv.l dtpsv.l dtrmm.l dtrmv.l \
	dtrsm.l dtrsv.l lsame.l sgbmv.l sgemm.l sgemv.l sger.l ssbmv.l \
	sspmv.l sspr.l sspr2.l ssymm.l ssymv.l ssyr.l ssyr2.l ssyr2k.l \
	ssyrk.l stbmv.l stbsv.l stpmv.l stpsv.l strmm.l strmv.l strsm.l \
	strsv.l xerbla.l zgbmv.l zgemm.l zgemv.l zgerc.l zgeru.l zhbmv.l \
	zhemm.l zhemv.l zher.l zher2.l zher2k.l zherk.l zhpmv.l zhpr.l \
	zhpr2.l zrotg.l zscal.l zsymm.l zsyr2k.l zsyrk.l ztbmv.l ztbsv.l \
	ztpmv.l ztpsv.l ztrmm.l ztrmv.l ztrsm.l ztrsv.l cbdsqr.l cgbbrd.l \
	cgbcon.l cgbequ.l cgbrfs.l cgbsv.l cgbsvx.l cgbtf2.l cgbtrf.l \
	cgbtrs.l cgebak.l cgebal.l cgebd2.l cgebrd.l cgecon.l cgeequ.l \
	cgees.l cgeesx.l cgeev.l cgeevx.l cgegs.l cgegv.l cgehd2.l cgehrd.l \
	cgelq2.l cgelqf.l cgels.l cgelss.l cgelsx.l cgeql2.l cgeqlf.l \
	cgeqpf.l cgeqr2.l cgeqrf.l cgerfs.l cgerq2.l cgerqf.l cgesv.l \
	cgesvd.l cgesvx.l cgetf2.l cgetrf.l cgetri.l cgetrs.l cggbak.l \
	cggbal.l cggglm.l cgghrd.l cgglse.l cggqrf.l cggrqf.l cggsvd.l \
	cggsvp.l cgtcon.l cgtrfs.l cgtsv.l cgtsvx.l cgttrf.l cgttrs.l \
	chbev.l chbevd.l chbevx.l chbgst.l chbgv.l chbtrd.l checon.l cheev.l \
	cheevd.l cheevx.l chegs2.l chegst.l chegv.l cherfs.l chesv.l chesvx.l \
	chetd2.l chetf2.l chetrd.l chetrf.l chetri.l chetrs.l chgeqz.l \
	chpcon.l chpev.l chpevd.l chpevx.l chpgst.l chpgv.l chprfs.l chpsv.l \
	chpsvx.l chptrd.l chptrf.l chptri.l chptrs.l chsein.l chseqr.l \
	clabrd.l clacgv.l clacon.l clacpy.l clacrm.l clacrt.l cladiv.l \
	claed0.l claed7.l claed8.l claein.l claesy.l claev2.l clags2.l \
	clagtm.l clahef.l clahqr.l clahrd.l claic1.l clangb.l clange.l \
	clangt.l clanhb.l clanhe.l clanhp.l clanhs.l clanht.l clansb.l \
	clansp.l clansy.l clantb.l clantp.l clantr.l clapll.l clapmt.l \
	claqgb.l claqge.l claqhb.l claqhe.l claqhp.l claqsb.l claqsp.l \
	claqsy.l clar2v.l clarf.l clarfb.l clarfg.l clarft.l clarfx.l \
	clargv.l clarnv.l clartg.l clartv.l clascl.l claset.l clasr.l \
	classq.l claswp.l clasyf.l clatbs.l clatps.l clatrd.l clatrs.l \
	clatzm.l clauu2.l clauum.l cpbcon.l cpbequ.l cpbrfs.l cpbstf.l \
	cpbsv.l cpbsvx.l cpbtf2.l cpbtrf.l cpbtrs.l cpocon.l cpoequ.l \
	cporfs.l cposv.l cposvx.l cpotf2.l cpotrf.l cpotri.l cpotrs.l \
	cppcon.l cppequ.l cpprfs.l cppsv.l cppsvx.l cpptrf.l cpptri.l \
	cpptrs.l cptcon.l cpteqr.l cptrfs.l cptsv.l cptsvx.l cpttrf.l \
	cpttrs.l crot.l cspcon.l cspmv.l cspr.l csprfs.l cspsv.l cspsvx.l \
	csptrf.l csptri.l csptrs.l csrot.l csrscl.l cstedc.l cstein.l \
	csteqr.l csycon.l csymv.l csyr.l csyrfs.l csysv.l csysvx.l csytf2.l \
	csytrf.l csytri.l csytrs.l ctbcon.l ctbrfs.l ctbtrs.l ctgevc.l \
	ctgsja.l ctpcon.l ctprfs.l ctptri.l ctptrs.l ctrcon.l ctrevc.l \
	ctrexc.l ctrrfs.l ctrsen.l ctrsna.l ctrsyl.l ctrti2.l ctrtri.l \
	ctrtrs.l ctzrqf.l cung2l.l cung2r.l cungbr.l cunghr.l cungl2.l \
	cunglq.l cungql.l cungqr.l cungr2.l cungrq.l cungtr.l cunm2l.l \
	cunm2r.l cunmbr.l cunmhr.l cunml2.l cunmlq.l cunmql.l cunmqr.l \
	cunmr2.l cunmrq.l cunmtr.l cupgtr.l cupmtr.l dbdsqr.l ddisna.l \
	dgbbrd.l dgbcon.l dgbequ.l dgbrfs.l dgbsv.l dgbsvx.l dgbtf2.l \
	dgbtrf.l dgbtrs.l dgebak.l dgebal.l dgebd2.l dgebrd.l dgecon.l \
	dgeequ.l dgees.l dgeesx.l dgeev.l dgeevx.l dgegs.l dgegv.l dgehd2.l \
	dgehrd.l dgelq2.l dgelqf.l dgels.l dgelss.l dgelsx.l dgeql2.l \
	dgeqlf.l dgeqpf.l dgeqr2.l dgeqrf.l dgerfs.l dgerq2.l dgerqf.l \
	dgesv.l dgesvd.l dgesvx.l dgetf2.l dgetrf.l dgetri.l dgetrs.l \
	dggbak.l dggbal.l dggglm.l dgghrd.l dgglse.l dggqrf.l dggrqf.l \
	dggsvd.l dggsvp.l dgtcon.l dgtrfs.l dgtsv.l dgtsvx.l dgttrf.l \
	dgttrs.l dhgeqz.l dhsein.l dhseqr.l dlabad.l dlabrd.l dlacon.l \
	dlacpy.l dladiv.l dlae2.l dlaebz.l dlaed0.l dlaed1.l dlaed2.l \
	dlaed3.l dlaed4.l dlaed5.l dlaed6.l dlaed7.l dlaed8.l dlaed9.l \
	dlaeda.l dlaein.l dlaev2.l dlaexc.l dlag2.l dlags2.l dlagtf.l \
	dlagtm.l dlagts.l dlahqr.l dlahrd.l dlaic1.l dlaln2.l dlamch.l \
	dlamrg.l dlangb.l dlange.l dlangt.l dlanhs.l dlansb.l dlansp.l \
	dlanst.l dlansy.l dlantb.l dlantp.l dlantr.l dlanv2.l dlapll.l \
	dlapmt.l dlapy2.l dlapy3.l dlaqgb.l dlaqge.l dlaqsb.l dlaqsp.l \
	dlaqsy.l dlaqtr.l dlar2v.l dlarf.l dlarfb.l dlarfg.l dlarft.l \
	dlarfx.l dlargv.l dlarnv.l dlartg.l dlartv.l dlaruv.l dlas2.l \
	dlascl.l dlaset.l dlasq1.l dlasq2.l dlasq3.l dlasq4.l dlasr.l \
	dlasrt.l dlassq.l dlasv2.l dlaswp.l dlasy2.l dlasyf.l dlatbs.l \
	dlatps.l dlatrd.l dlatrs.l dlatzm.l dlauu2.l dlauum.l dopgtr.l \
	dopmtr.l dorg2l.l dorg2r.l dorgbr.l dorghr.l dorgl2.l dorglq.l \
	dorgql.l dorgqr.l dorgr2.l dorgrq.l dorgtr.l dorm2l.l dorm2r.l \
	dormbr.l dormhr.l dorml2.l dormlq.l dormql.l dormqr.l dormr2.l \
	dormrq.l dormtr.l dpbcon.l dpbequ.l dpbrfs.l dpbstf.l dpbsv.l \
	dpbsvx.l dpbtf2.l dpbtrf.l dpbtrs.l dpocon.l dpoequ.l dporfs.l \
	dposv.l dposvx.l dpotf2.l dpotrf.l dpotri.l dpotrs.l dppcon.l \
	dppequ.l dpprfs.l dppsv.l dppsvx.l dpptrf.l dpptri.l dpptrs.l \
	dptcon.l dpteqr.l dptrfs.l dptsv.l dptsvx.l dpttrf.l dpttrs.l \
	drscl.l dsbev.l dsbevd.l dsbevx.l dsbgst.l dsbgv.l dsbtrd.l dsecnd.l \
	dspcon.l dspev.l dspevd.l dspevx.l dspgst.l dspgv.l dsprfs.l dspsv.l \
	dspsvx.l dsptrd.l dsptrf.l dsptri.l dsptrs.l dstebz.l dstedc.l \
	dstein.l dsteqr.l dsterf.l dstev.l dstevd.l dstevx.l dsycon.l \
	dsyev.l dsyevd.l dsyevx.l dsygs2.l dsygst.l dsygv.l dsyrfs.l dsysv.l \
	dsysvx.l dsytd2.l dsytf2.l dsytrd.l dsytrf.l dsytri.l dsytrs.l \
	dtbcon.l dtbrfs.l dtbtrs.l dtgevc.l dtgsja.l dtpcon.l dtprfs.l \
	dtptri.l dtptrs.l dtrcon.l dtrevc.l dtrexc.l dtrrfs.l dtrsen.l \
	dtrsna.l dtrsyl.l dtrti2.l dtrtri.l dtrtrs.l dtzrqf.l dzsum1.l \
	icmax1.l ilaenv.l izmax1.l lapack.l lsamen.l sbdsqr.l scsum1.l \
	sdisna.l second.l sgbbrd.l sgbcon.l sgbequ.l sgbrfs.l sgbsv.l \
	sgbsvx.l sgbtf2.l sgbtrf.l sgbtrs.l sgebak.l sgebal.l sgebd2.l \
	sgebrd.l sgecon.l sgeequ.l sgees.l sgeesx.l sgeev.l sgeevx.l sgegs.l \
	sgegv.l sgehd2.l sgehrd.l sgelq2.l sgelqf.l sgels.l sgelss.l sgelsx.l \
	sgeql2.l sgeqlf.l sgeqpf.l sgeqr2.l sgeqrf.l sgerfs.l sgerq2.l \
	sgerqf.l sgesv.l sgesvd.l sgesvx.l sgetf2.l sgetrf.l sgetri.l \
	sgetrs.l sggbak.l sggbal.l sggglm.l sgghrd.l sgglse.l sggqrf.l \
	sggrqf.l sggsvd.l sggsvp.l sgtcon.l sgtrfs.l sgtsv.l sgtsvx.l \
	sgttrf.l sgttrs.l shgeqz.l shsein.l shseqr.l slabad.l slabrd.l \
	slacon.l slacpy.l sladiv.l slae2.l slaebz.l slaed0.l slaed1.l \
	slaed2.l slaed3.l slaed4.l slaed5.l slaed6.l slaed7.l slaed8.l \
	slaed9.l slaeda.l slaein.l slaev2.l slaexc.l slag2.l slags2.l \
	slagtf.l slagtm.l slagts.l slahqr.l slahrd.l slaic1.l slaln2.l \
	slamch.l slamrg.l slangb.l slange.l slangt.l slanhs.l slansb.l \
	slansp.l slanst.l slansy.l slantb.l slantp.l slantr.l slanv2.l \
	slapll.l slapmt.l slapy2.l slapy3.l slaqgb.l slaqge.l slaqsb.l \
	slaqsp.l slaqsy.l slaqtr.l slar2v.l slarf.l slarfb.l slarfg.l \
	slarft.l slarfx.l slargv.l slarnv.l slartg.l slartv.l slaruv.l \
	slas2.l slascl.l slaset.l slasq1.l slasq2.l slasq3.l slasq4.l \
	slasr.l slasrt.l slassq.l slasv2.l slaswp.l slasy2.l slasyf.l \
	slatbs.l slatps.l slatrd.l slatrs.l slatzm.l slauu2.l slauum.l \
	sopgtr.l sopmtr.l sorg2l.l sorg2r.l sorgbr.l sorghr.l sorgl2.l \
	sorglq.l sorgql.l sorgqr.l sorgr2.l sorgrq.l sorgtr.l sorm2l.l \
	sorm2r.l sormbr.l sormhr.l sorml2.l sormlq.l sormql.l sormqr.l \
	sormr2.l sormrq.l sormtr.l spbcon.l spbequ.l spbrfs.l spbstf.l \
	spbsv.l spbsvx.l spbtf2.l spbtrf.l spbtrs.l spocon.l spoequ.l \
	sporfs.l sposv.l sposvx.l spotf2.l spotrf.l spotri.l spotrs.l \
	sppcon.l sppequ.l spprfs.l sppsv.l sppsvx.l spptrf.l spptri.l \
	spptrs.l sptcon.l spteqr.l sptrfs.l sptsv.l sptsvx.l spttrf.l \
	spttrs.l srscl.l ssbev.l ssbevd.l ssbevx.l ssbgst.l ssbgv.l ssbtrd.l \
	sspcon.l sspev.l sspevd.l sspevx.l sspgst.l sspgv.l ssprfs.l sspsv.l \
	sspsvx.l ssptrd.l ssptrf.l ssptri.l ssptrs.l sstebz.l sstedc.l \
	sstein.l ssteqr.l ssterf.l sstev.l sstevd.l sstevx.l ssycon.l \
	ssyev.l ssyevd.l ssyevx.l ssygs2.l ssygst.l ssygv.l ssyrfs.l ssysv.l \
	ssysvx.l ssytd2.l ssytf2.l ssytrd.l ssytrf.l ssytri.l ssytrs.l \
	stbcon.l stbrfs.l stbtrs.l stgevc.l stgsja.l stpcon.l stprfs.l \
	stptri.l stptrs.l strcon.l strevc.l strexc.l strrfs.l strsen.l \
	strsna.l strsyl.l strti2.l strtri.l strtrs.l stzrqf.l zbcon.l \
	zbdsqr.l zdrot.l zdrscl.l zgbbrd.l zgbcon.l zgbequ.l zgbrfs.l \
	zgbsv.l zgbsvx.l zgbtf2.l zgbtrf.l zgbtrs.l zgebak.l zgebal.l \
	zgebd2.l zgebrd.l zgecon.l zgeequ.l zgees.l zgeesx.l zgeev.l zgeevx.l \
	zgegs.l zgegv.l zgehd2.l zgehrd.l zgelq2.l zgelqf.l zgels.l zgelss.l \
	zgelsx.l zgeql2.l zgeqlf.l zgeqpf.l zgeqr2.l zgeqrf.l zgerfs.l \
	zgerq2.l zgerqf.l zgesv.l zgesvd.l zgesvx.l zgetf2.l zgetrf.l \
	zgetri.l zgetrs.l zggbak.l zggbal.l zggglm.l zgghrd.l zgglse.l \
	zggqrf.l zggrqf.l zggsvd.l zggsvp.l zgtcon.l zgtrfs.l zgtsv.l \
	zgtsvx.l zgttrf.l zgttrs.l zhbev.l zhbevd.l zhbevx.l zhbgst.l \
	zhbgv.l zhbtrd.l zhecon.l zheev.l zheevd.l zheevx.l zhegs2.l zhegst.l \
	zhegv.l zherfs.l zhesv.l zhesvx.l zhetd2.l zhetf2.l zhetrd.l zhetrf.l \
	zhetri.l zhetrs.l zhgeqz.l zhpcon.l zhpev.l zhpevd.l zhpevx.l \
	zhpgst.l zhpgv.l zhprfs.l zhpsv.l zhpsvx.l zhptrd.l zhptrf.l zhptri.l \
	zhptrs.l zhsein.l zhseqr.l zlabrd.l zlacgv.l zlacon.l zlacpy.l \
	zlacrm.l zlacrt.l zladiv.l zlaed0.l zlaed7.l zlaed8.l zlaein.l \
	zlaesy.l zlaev2.l zlags2.l zlagtm.l zlahef.l zlahqr.l zlahrd.l \
	zlaic1.l zlangb.l zlange.l zlangt.l zlanhb.l zlanhe.l zlanhp.l \
	zlanhs.l zlanht.l zlansb.l zlansp.l zlansy.l zlantb.l zlantp.l \
	zlantr.l zlapll.l zlapmt.l zlaqgb.l zlaqge.l zlaqhb.l zlaqhe.l \
	zlaqhp.l zlaqsb.l zlaqsp.l zlaqsy.l zlar2v.l zlarf.l zlarfb.l \
	zlarfg.l zlarft.l zlarfx.l zlargv.l zlarnv.l zlartg.l zlartv.l \
	zlascl.l zlaset.l zlasr.l zlassq.l zlaswp.l zlasyf.l zlatbs.l \
	zlatps.l zlatrd.l zlatrs.l zlatzm.l zlauu2.l zlauum.l zpbcon.l \
	zpbequ.l zpbrfs.l zpbstf.l zpbsv.l zpbsvx.l zpbtf2.l zpbtrf.l \
	zpbtrs.l zpocon.l zpoequ.l zporfs.l zposv.l zposvx.l zpotf2.l \
	zpotrf.l zpotri.l zpotrs.l zppcon.l zppequ.l zpprfs.l zppsv.l \
	zppsvx.l zpptrf.l zpptri.l zpptrs.l zptcon.l zpteqr.l zptrfs.l \
	zptsv.l zptsvx.l zpttrf.l zpttrs.l zrot.l zspcon.l zspmv.l zspr.l \
	zsprfs.l zspsv.l zspsvx.l zsptrf.l zsptri.l zsptrs.l zsrscl.l \
	zstedc.l zstein.l zsteqr.l zsycon.l zsymv.l zsyr.l zsyrfs.l zsysv.l \
	zsysvx.l zsytf2.l zsytrf.l zsytri.l zsytrs.l ztbcon.l ztbrfs.l \
	ztbtrs.l ztgevc.l ztgsja.l ztpcon.l ztprfs.l ztptri.l ztptrs.l \
	ztrcon.l ztrevc.l ztrexc.l ztrrfs.l ztrsen.l ztrsna.l ztrsyl.l \
	ztrti2.l ztrtri.l ztrtrs.l ztzrqf.l zung2l.l zung2r.l zungbr.l \
	zunghr.l zungl2.l zunglq.l zungql.l zungqr.l zungr2.l zungrq.l \
	zungtr.l zunm2l.l zunm2r.l zunmbr.l zunmhr.l zunml2.l zunmlq.l \
	zunmql.l zunmqr.l zunmr2.l zunmrq.l zunmtr.l zupgtr.l zupmtr.l \

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/BLAS/SRC/libblas.* ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/SRC/liblapack.* ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "elf"
	${LN} -sf libblas.so.2 ${PREFIX}/lib/libblas.so
	${LN} -sf liblapack.so.2 ${PREFIX}/lib/liblapack.so
.else
	${LN} -sf libblas.so.2.0 ${PREFIX}/lib/libblas.so
	${LN} -sf liblapack.so.2.0 ${PREFIX}/lib/liblapack.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${INSTALL_MAN} ${WRKDIR}/blas/man/manl/*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${WRKDIR}/man/manl/*.l ${PREFIX}/man/manl

.include <bsd.port.post.mk>
