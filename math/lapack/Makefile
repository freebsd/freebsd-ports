# New ports collection makefile for:    lapack
# Date created:         2 July 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	lapack
PORTVERSION=	3.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/
DISTNAME=	LAPACK
DISTFILES=	lapack.tgz manpages.tgz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A library of Fortran 77 subroutines for linear algebra

DIST_SUBDIR=	lapack

INSTALLS_SHLIB=	yes
PLIST=		${WRKDIR}/PLIST

MANCOMPRESSED=	maybe
MANL=	cbdsqr.l cgbbrd.l cgbcon.l cgbequ.l cgbmv.l cgbrfs.l cgbsv.l cgbsvx.l \
	cgbtf2.l cgbtrf.l cgbtrs.l cgebak.l cgebal.l cgebd2.l cgebrd.l \
	cgecon.l cgeequ.l cgees.l cgeesx.l cgeev.l cgeevx.l cgegs.l cgegv.l \
	cgehd2.l cgehrd.l cgelq2.l cgelqf.l cgels.l cgelsd.l cgelss.l cgelsx.l \
	cgelsy.l cgemm.l cgemv.l cgeql2.l cgeqlf.l cgeqp3.l cgeqpf.l cgeqr2.l \
	cgeqrf.l cgerc.l cgerfs.l cgerq2.l cgerqf.l cgeru.l cgesc2.l cgesdd.l \
	cgesv.l cgesvd.l cgesvx.l cgetc2.l cgetf2.l cgetrf.l cgetri.l cgetrs.l \
	cggbak.l cggbal.l cgges.l cggesx.l cggev.l cggevx.l cggglm.l cgghrd.l \
	cgglse.l cggqrf.l cggrqf.l cggsvd.l cggsvp.l cgtcon.l cgtrfs.l cgtsv.l \
	cgtsvx.l cgttrf.l cgttrs.l cgtts2.l chbev.l chbevd.l chbevx.l chbgst.l \
	chbgv.l chbgvd.l chbgvx.l chbmv.l chbtrd.l checon.l cheev.l cheevd.l \
	cheevr.l cheevx.l chegs2.l chegst.l chegv.l chegvd.l chegvx.l chemm.l \
	chemv.l cher.l cher2.l cher2k.l cherfs.l cherk.l chesv.l chesvx.l \
	chetd2.l chetf2.l chetrd.l chetrf.l chetri.l chetrs.l chgeqz.l \
	chpcon.l chpev.l chpevd.l chpevx.l chpgst.l chpgv.l chpgvd.l chpgvx.l \
	chpmv.l chpr.l chpr2.l chprfs.l chpsv.l chpsvx.l chptrd.l chptrf.l \
	chptri.l chptrs.l chsein.l chseqr.l clabrd.l clacgv.l clacon.l \
	clacp2.l clacpy.l clacrm.l clacrt.l cladiv.l claed0.l claed7.l \
	claed8.l claein.l claesy.l claev2.l clags2.l clagtm.l clahef.l \
	clahqr.l clahrd.l claic1.l clals0.l clalsa.l clalsd.l clangb.l \
	clange.l clangt.l clanhb.l clanhe.l clanhp.l clanhs.l clanht.l \
	clansb.l clansp.l clansy.l clantb.l clantp.l clantr.l clapll.l \
	clapmt.l claqgb.l claqge.l claqhb.l claqhe.l claqhp.l claqp2.l \
	claqps.l claqsb.l claqsp.l claqsy.l clar1v.l clar2v.l clarcm.l clarf.l \
	clarfb.l clarfg.l clarft.l clarfx.l clargv.l clarnv.l clarrv.l \
	clartg.l clartv.l clarz.l clarzb.l clarzt.l clascl.l claset.l clasr.l \
	classq.l claswp.l clasyf.l clatbs.l clatdf.l clatps.l clatrd.l \
	clatrs.l clatrz.l clatzm.l clauu2.l clauum.l cpbcon.l cpbequ.l \
	cpbrfs.l cpbstf.l cpbsv.l cpbsvx.l cpbtf2.l cpbtrf.l cpbtrs.l cpocon.l \
	cpoequ.l cporfs.l cposv.l cposvx.l cpotf2.l cpotrf.l cpotri.l cpotrs.l \
	cppcon.l cppequ.l cpprfs.l cppsv.l cppsvx.l cpptrf.l cpptri.l cpptrs.l \
	cptcon.l cpteqr.l cptrfs.l cptsv.l cptsvx.l cpttrf.l cpttrs.l cptts2.l \
	crot.l cscal.l cspcon.l cspmv.l cspr.l csprfs.l cspsv.l cspsvx.l \
	csptrf.l csptri.l csptrs.l csrot.l csrscl.l cstedc.l cstegr.l cstein.l \
	csteqr.l csycon.l csymm.l csymv.l csyr.l csyr2k.l csyrfs.l csyrk.l \
	csysv.l csysvx.l csytf2.l csytrf.l csytri.l csytrs.l ctbcon.l ctbmv.l \
	ctbrfs.l ctbsv.l ctbtrs.l ctgevc.l ctgex2.l ctgexc.l ctgsen.l ctgsja.l \
	ctgsna.l ctgsy2.l ctgsyl.l ctpcon.l ctpmv.l ctprfs.l ctpsv.l ctptri.l \
	ctptrs.l ctrcon.l ctrevc.l ctrexc.l ctrmm.l ctrmv.l ctrrfs.l ctrsen.l \
	ctrsm.l ctrsna.l ctrsv.l ctrsyl.l ctrti2.l ctrtri.l ctrtrs.l ctzrqf.l \
	ctzrzf.l cung2l.l cung2r.l cungbr.l cunghr.l cungl2.l cunglq.l \
	cungql.l cungqr.l cungr2.l cungrq.l cungtr.l cunm2l.l cunm2r.l \
	cunmbr.l cunmhr.l cunml2.l cunmlq.l cunmql.l cunmqr.l cunmr2.l \
	cunmr3.l cunmrq.l cunmrz.l cunmtr.l cupgtr.l cupmtr.l dbdsdc.l \
	dbdsqr.l dcabs1.l ddisna.l dgbbrd.l dgbcon.l dgbequ.l dgbmv.l dgbrfs.l \
	dgbsv.l dgbsvx.l dgbtf2.l dgbtrf.l dgbtrs.l dgebak.l dgebal.l dgebd2.l \
	dgebrd.l dgecon.l dgeequ.l dgees.l dgeesx.l dgeev.l dgeevx.l dgegs.l \
	dgegv.l dgehd2.l dgehrd.l dgelq2.l dgelqf.l dgels.l dgelsd.l dgelss.l \
	dgelsx.l dgelsy.l dgemm.l dgemv.l dgeql2.l dgeqlf.l dgeqp3.l dgeqpf.l \
	dgeqr2.l dgeqrf.l dger.l dgerfs.l dgerq2.l dgerqf.l dgesc2.l dgesdd.l \
	dgesv.l dgesvd.l dgesvx.l dgetc2.l dgetf2.l dgetrf.l dgetri.l dgetrs.l \
	dggbak.l dggbal.l dgges.l dggesx.l dggev.l dggevx.l dggglm.l dgghrd.l \
	dgglse.l dggqrf.l dggrqf.l dggsvd.l dggsvp.l dgtcon.l dgtrfs.l dgtsv.l \
	dgtsvx.l dgttrf.l dgttrs.l dgtts2.l dhgeqz.l dhsein.l dhseqr.l \
	dlabad.l dlabrd.l dlacon.l dlacpy.l dladiv.l dlae2.l dlaebz.l dlaed0.l \
	dlaed1.l dlaed2.l dlaed3.l dlaed4.l dlaed5.l dlaed6.l dlaed7.l \
	dlaed8.l dlaed9.l dlaeda.l dlaein.l dlaev2.l dlaexc.l dlag2.l dlags2.l \
	dlagtf.l dlagtm.l dlagts.l dlagv2.l dlahqr.l dlahrd.l dlaic1.l \
	dlaln2.l dlals0.l dlalsa.l dlalsd.l dlamch.l dlamrg.l dlangb.l \
	dlange.l dlangt.l dlanhs.l dlansb.l dlansp.l dlanst.l dlansy.l \
	dlantb.l dlantp.l dlantr.l dlanv2.l dlapll.l dlapmt.l dlapy2.l \
	dlapy3.l dlaqgb.l dlaqge.l dlaqp2.l dlaqps.l dlaqsb.l dlaqsp.l \
	dlaqsy.l dlaqtr.l dlar1v.l dlar2v.l dlarf.l dlarfb.l dlarfg.l dlarft.l \
	dlarfx.l dlargv.l dlarnv.l dlarrb.l dlarre.l dlarrf.l dlarrv.l \
	dlartg.l dlartv.l dlaruv.l dlarz.l dlarzb.l dlarzt.l dlas2.l dlascl.l \
	dlasd0.l dlasd1.l dlasd2.l dlasd3.l dlasd4.l dlasd5.l dlasd6.l \
	dlasd7.l dlasd8.l dlasd9.l dlasda.l dlasdq.l dlasdt.l dlaset.l \
	dlasq1.l dlasq2.l dlasq3.l dlasq4.l dlasq5.l dlasq6.l dlasr.l dlasrt.l \
	dlassq.l dlasv2.l dlaswp.l dlasy2.l dlasyf.l dlatbs.l dlatdf.l \
	dlatps.l dlatrd.l dlatrs.l dlatrz.l dlatzm.l dlauu2.l dlauum.l \
	dopgtr.l dopmtr.l dorg2l.l dorg2r.l dorgbr.l dorghr.l dorgl2.l \
	dorglq.l dorgql.l dorgqr.l dorgr2.l dorgrq.l dorgtr.l dorm2l.l \
	dorm2r.l dormbr.l dormhr.l dorml2.l dormlq.l dormql.l dormqr.l \
	dormr2.l dormr3.l dormrq.l dormrz.l dormtr.l dpbcon.l dpbequ.l \
	dpbrfs.l dpbstf.l dpbsv.l dpbsvx.l dpbtf2.l dpbtrf.l dpbtrs.l dpocon.l \
	dpoequ.l dporfs.l dposv.l dposvx.l dpotf2.l dpotrf.l dpotri.l dpotrs.l \
	dppcon.l dppequ.l dpprfs.l dppsv.l dppsvx.l dpptrf.l dpptri.l dpptrs.l \
	dptcon.l dpteqr.l dptrfs.l dptsv.l dptsvx.l dpttrf.l dpttrs.l dptts2.l \
	drscl.l dsbev.l dsbevd.l dsbevx.l dsbgst.l dsbgv.l dsbgvd.l dsbgvx.l \
	dsbmv.l dsbtrd.l dsecnd.l dspcon.l dspev.l dspevd.l dspevx.l dspgst.l \
	dspgv.l dspgvd.l dspgvx.l dspmv.l dspr.l dspr2.l dsprfs.l dspsv.l \
	dspsvx.l dsptrd.l dsptrf.l dsptri.l dsptrs.l dstebz.l dstedc.l \
	dstegr.l dstein.l dsteqr.l dsterf.l dstev.l dstevd.l dstevr.l dstevx.l \
	dsycon.l dsyev.l dsyevd.l dsyevr.l dsyevx.l dsygs2.l dsygst.l dsygv.l \
	dsygvd.l dsygvx.l dsymm.l dsymv.l dsyr.l dsyr2.l dsyr2k.l dsyrfs.l \
	dsyrk.l dsysv.l dsysvx.l dsytd2.l dsytf2.l dsytrd.l dsytrf.l dsytri.l \
	dsytrs.l dtbcon.l dtbmv.l dtbrfs.l dtbsv.l dtbtrs.l dtgevc.l dtgex2.l \
	dtgexc.l dtgsen.l dtgsja.l dtgsna.l dtgsy2.l dtgsyl.l dtpcon.l dtpmv.l \
	dtprfs.l dtpsv.l dtptri.l dtptrs.l dtrcon.l dtrevc.l dtrexc.l dtrmm.l \
	dtrmv.l dtrrfs.l dtrsen.l dtrsm.l dtrsna.l dtrsv.l dtrsyl.l dtrti2.l \
	dtrtri.l dtrtrs.l dtzrqf.l dtzrzf.l dzsum1.l icmax1.l ilaenv.l \
	izmax1.l lapack.l lsame.l lsamen.l sbdsdc.l sbdsqr.l scsum1.l \
	sdisna.l second.l sgbbrd.l sgbcon.l sgbequ.l sgbmv.l sgbrfs.l sgbsv.l \
	sgbsvx.l sgbtf2.l sgbtrf.l sgbtrs.l sgebak.l sgebal.l sgebd2.l \
	sgebrd.l sgecon.l sgeequ.l sgees.l sgeesx.l sgeev.l sgeevx.l sgegs.l \
	sgegv.l sgehd2.l sgehrd.l sgelq2.l sgelqf.l sgels.l sgelsd.l sgelss.l \
	sgelsx.l sgelsy.l sgemm.l sgemv.l sgeql2.l sgeqlf.l sgeqp3.l sgeqpf.l \
	sgeqr2.l sgeqrf.l sger.l sgerfs.l sgerq2.l sgerqf.l sgesc2.l sgesdd.l \
	sgesv.l sgesvd.l sgesvx.l sgetc2.l sgetf2.l sgetrf.l sgetri.l sgetrs.l \
	sggbak.l sggbal.l sgges.l sggesx.l sggev.l sggevx.l sggglm.l sgghrd.l \
	sgglse.l sggqrf.l sggrqf.l sggsvd.l sggsvp.l sgtcon.l sgtrfs.l sgtsv.l \
	sgtsvx.l sgttrf.l sgttrs.l sgtts2.l shgeqz.l shsein.l shseqr.l \
	slabad.l slabrd.l slacon.l slacpy.l sladiv.l slae2.l slaebz.l slaed0.l \
	slaed1.l slaed2.l slaed3.l slaed4.l slaed5.l slaed6.l slaed7.l \
	slaed8.l slaed9.l slaeda.l slaein.l slaev2.l slaexc.l slag2.l slags2.l \
	slagtf.l slagtm.l slagts.l slagv2.l slahqr.l slahrd.l slaic1.l \
	slaln2.l slals0.l slalsa.l slalsd.l slamch.l slamrg.l slangb.l \
	slange.l slangt.l slanhs.l slansb.l slansp.l slanst.l slansy.l \
	slantb.l slantp.l slantr.l slanv2.l slapll.l slapmt.l slapy2.l \
	slapy3.l slaqgb.l slaqge.l slaqp2.l slaqps.l slaqsb.l slaqsp.l \
	slaqsy.l slaqtr.l slar1v.l slar2v.l slarf.l slarfb.l slarfg.l slarft.l \
	slarfx.l slargv.l slarnv.l slarrb.l slarre.l slarrf.l slarrv.l \
	slartg.l slartv.l slaruv.l slarz.l slarzb.l slarzt.l slas2.l slascl.l \
	slasd0.l slasd1.l slasd2.l slasd3.l slasd4.l slasd5.l slasd6.l \
	slasd7.l slasd8.l slasd9.l slasda.l slasdq.l slasdt.l slaset.l \
	slasq1.l slasq2.l slasq3.l slasq4.l slasq5.l slasq6.l slasr.l slasrt.l \
	slassq.l slasv2.l slaswp.l slasy2.l slasyf.l slatbs.l slatdf.l \
	slatps.l slatrd.l slatrs.l slatrz.l slatzm.l slauu2.l slauum.l \
	sopgtr.l sopmtr.l sorg2l.l sorg2r.l sorgbr.l sorghr.l sorgl2.l \
	sorglq.l sorgql.l sorgqr.l sorgr2.l sorgrq.l sorgtr.l sorm2l.l \
	sorm2r.l sormbr.l sormhr.l sorml2.l sormlq.l sormql.l sormqr.l \
	sormr2.l sormr3.l sormrq.l sormrz.l sormtr.l spbcon.l spbequ.l \
	spbrfs.l spbstf.l spbsv.l spbsvx.l spbtf2.l spbtrf.l spbtrs.l spocon.l \
	spoequ.l sporfs.l sposv.l sposvx.l spotf2.l spotrf.l spotri.l spotrs.l \
	sppcon.l sppequ.l spprfs.l sppsv.l sppsvx.l spptrf.l spptri.l spptrs.l \
	sptcon.l spteqr.l sptrfs.l sptsv.l sptsvx.l spttrf.l spttrs.l sptts2.l \
	srscl.l ssbev.l ssbevd.l ssbevx.l ssbgst.l ssbgv.l ssbgvd.l ssbgvx.l \
	ssbmv.l ssbtrd.l sspcon.l sspev.l sspevd.l sspevx.l sspgst.l sspgv.l \
	sspgvd.l sspgvx.l sspmv.l sspr.l sspr2.l ssprfs.l sspsv.l sspsvx.l \
	ssptrd.l ssptrf.l ssptri.l ssptrs.l sstebz.l sstedc.l sstegr.l \
	sstein.l ssteqr.l ssterf.l sstev.l sstevd.l sstevr.l sstevx.l ssycon.l \
	ssyev.l ssyevd.l ssyevr.l ssyevx.l ssygs2.l ssygst.l ssygv.l ssygvd.l \
	ssygvx.l ssymm.l ssymv.l ssyr.l ssyr2.l ssyr2k.l ssyrfs.l ssyrk.l \
	ssysv.l ssysvx.l ssytd2.l ssytf2.l ssytrd.l ssytrf.l ssytri.l ssytrs.l \
	stbcon.l stbmv.l stbrfs.l stbsv.l stbtrs.l stgevc.l stgex2.l stgexc.l \
	stgsen.l stgsja.l stgsna.l stgsy2.l stgsyl.l stpcon.l stpmv.l stprfs.l \
	stpsv.l stptri.l stptrs.l strcon.l strevc.l strexc.l strmm.l strmv.l \
	strrfs.l strsen.l strsm.l strsna.l strsv.l strsyl.l strti2.l strtri.l \
	strtrs.l stzrqf.l stzrzf.l xerbla.l zbcon.l zbdsqr.l zdrot.l \
	zdrscl.l zgbbrd.l zgbcon.l zgbequ.l zgbmv.l zgbrfs.l zgbsv.l zgbsvx.l \
	zgbtf2.l zgbtrf.l zgbtrs.l zgebak.l zgebal.l zgebd2.l zgebrd.l \
	zgecon.l zgeequ.l zgees.l zgeesx.l zgeev.l zgeevx.l zgegs.l zgegv.l \
	zgehd2.l zgehrd.l zgelq2.l zgelqf.l zgels.l zgelsd.l zgelss.l zgelsx.l \
	zgelsy.l zgemm.l zgemv.l zgeql2.l zgeqlf.l zgeqp3.l zgeqpf.l zgeqr2.l \
	zgeqrf.l zgerc.l zgerfs.l zgerq2.l zgerqf.l zgeru.l zgesc2.l zgesdd.l \
	zgesv.l zgesvd.l zgesvx.l zgetc2.l zgetf2.l zgetrf.l zgetri.l zgetrs.l \
	zggbak.l zggbal.l zgges.l zggesx.l zggev.l zggevx.l zggglm.l zgghrd.l \
	zgglse.l zggqrf.l zggrqf.l zggsvd.l zggsvp.l zgtcon.l zgtrfs.l zgtsv.l \
	zgtsvx.l zgttrf.l zgttrs.l zgtts2.l zhbev.l zhbevd.l zhbevx.l zhbgst.l \
	zhbgv.l zhbgvd.l zhbgvx.l zhbmv.l zhbtrd.l zhecon.l zheev.l zheevd.l \
	zheevr.l zheevx.l zhegs2.l zhegst.l zhegv.l zhegvd.l zhegvx.l zhemm.l \
	zhemv.l zher.l zher2.l zher2k.l zherfs.l zherk.l zhesv.l zhesvx.l \
	zhetd2.l zhetf2.l zhetrd.l zhetrf.l zhetri.l zhetrs.l zhgeqz.l \
	zhpcon.l zhpev.l zhpevd.l zhpevx.l zhpgst.l zhpgv.l zhpgvd.l zhpgvx.l \
	zhpmv.l zhpr.l zhpr2.l zhprfs.l zhpsv.l zhpsvx.l zhptrd.l zhptrf.l \
	zhptri.l zhptrs.l zhsein.l zhseqr.l zlabrd.l zlacgv.l zlacon.l \
	zlacp2.l zlacpy.l zlacrm.l zlacrt.l zladiv.l zlaed0.l zlaed7.l \
	zlaed8.l zlaein.l zlaesy.l zlaev2.l zlags2.l zlagtm.l zlahef.l \
	zlahqr.l zlahrd.l zlaic1.l zlals0.l zlalsa.l zlalsd.l zlangb.l \
	zlange.l zlangt.l zlanhb.l zlanhe.l zlanhp.l zlanhs.l zlanht.l \
	zlansb.l zlansp.l zlansy.l zlantb.l zlantp.l zlantr.l zlapll.l \
	zlapmt.l zlaqgb.l zlaqge.l zlaqhb.l zlaqhe.l zlaqhp.l zlaqp2.l \
	zlaqps.l zlaqsb.l zlaqsp.l zlaqsy.l zlar1v.l zlar2v.l zlarcm.l zlarf.l \
	zlarfb.l zlarfg.l zlarft.l zlarfx.l zlargv.l zlarnv.l zlarrv.l \
	zlartg.l zlartv.l zlarz.l zlarzb.l zlarzt.l zlascl.l zlaset.l zlasr.l \
	zlassq.l zlaswp.l zlasyf.l zlatbs.l zlatdf.l zlatps.l zlatrd.l \
	zlatrs.l zlatrz.l zlatzm.l zlauu2.l zlauum.l zpbcon.l zpbequ.l \
	zpbrfs.l zpbstf.l zpbsv.l zpbsvx.l zpbtf2.l zpbtrf.l zpbtrs.l zpocon.l \
	zpoequ.l zporfs.l zposv.l zposvx.l zpotf2.l zpotrf.l zpotri.l zpotrs.l \
	zppcon.l zppequ.l zpprfs.l zppsv.l zppsvx.l zpptrf.l zpptri.l zpptrs.l \
	zptcon.l zpteqr.l zptrfs.l zptsv.l zptsvx.l zpttrf.l zpttrs.l zptts2.l \
	zrot.l zrotg.l zscal.l zspcon.l zspmv.l zspr.l zsprfs.l zspsv.l \
	zspsvx.l zsptrf.l zsptri.l zsptrs.l zstedc.l zstegr.l zstein.l \
	zsteqr.l zsycon.l zsymm.l zsymv.l zsyr.l zsyr2k.l zsyrfs.l zsyrk.l \
	zsysv.l zsysvx.l zsytf2.l zsytrf.l zsytri.l zsytrs.l ztbcon.l ztbmv.l \
	ztbrfs.l ztbsv.l ztbtrs.l ztgevc.l ztgex2.l ztgexc.l ztgsen.l ztgsja.l \
	ztgsna.l ztgsy2.l ztgsyl.l ztpcon.l ztpmv.l ztprfs.l ztpsv.l ztptri.l \
	ztptrs.l ztrcon.l ztrevc.l ztrexc.l ztrmm.l ztrmv.l ztrrfs.l ztrsen.l \
	ztrsm.l ztrsna.l ztrsv.l ztrsyl.l ztrti2.l ztrtri.l ztrtrs.l ztzrqf.l \
	ztzrzf.l zung2l.l zung2r.l zungbr.l zunghr.l zungl2.l zunglq.l \
	zungql.l zungqr.l zungr2.l zungrq.l zungtr.l zunm2l.l zunm2r.l \
	zunmbr.l zunmhr.l zunml2.l zunmlq.l zunmql.l zunmqr.l zunmr2.l \
	zunmr3.l zunmrq.l zunmrz.l zunmtr.l zupgtr.l zupmtr.l

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	OSVERSION=${OSVERSION}

pre-fetch:
	@${ECHO} "You can override FC and FFLAGS on the command line."
.if !defined(ENABLE_TESTING) || ${ENABLE_TESTING} != "YES"
	@${ECHO} "Set ENABLE_TESTING to YES to enable testing and timing."
.endif
pre-install:
.if !defined(NOPROFILE)
	@${CAT} ${PKGDIR}/pkg-plist > ${PLIST}
.else
	@${SED} -e /_p.a/d ${PKGDIR}/pkg-plist > ${PLIST}
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/BLAS/SRC/libblas.* ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/SRC/liblapack.* ${PREFIX}/lib
.if !defined(NOPROFILE)
	${INSTALL_DATA} ${WRKSRC}/BLAS/SRC/libblas_p.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/SRC/liblapack_p.a ${PREFIX}/lib
.endif
.if ${PORTOBJFORMAT} == "elf"
	${LN} -sf libblas.so.2 ${PREFIX}/lib/libblas.so
	${LN} -sf liblapack.so.3 ${PREFIX}/lib/liblapack.so
.else
	${LN} -sf libblas.so.2.0 ${PREFIX}/lib/libblas.so
	${LN} -sf liblapack.so.3.0 ${PREFIX}/lib/liblapack.so
.endif
	${INSTALL_MAN} ${WRKDIR}/blas/man/manl/*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${WRKDIR}/man/manl/[a-c]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${WRKDIR}/man/manl/[d-l]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${WRKDIR}/man/manl/[m-s]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${WRKDIR}/man/manl/[t-z]*.l ${PREFIX}/man/manl
.if !defined(NOMANCOMPRESS)
.for f in ${MANL}
	@${GZIP_CMD} ${PREFIX}/man/manl/${f}
.endfor
.endif

.include <bsd.port.post.mk>
