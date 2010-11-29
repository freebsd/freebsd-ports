# Ports collection makefile for: gotoblas
# Date created:         20070203
# Whom:			Sato Hiroki <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gotoblas
PORTVERSION=	2.${GOTOBLAS2VER}
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|maho/gotoblas|} \
		ftp://ftp.netlib.org/lapack/:lapack \
		ftp://ftp.netlib.org/lapack/timing/:lapack_tmg \
		ftp://ftp.netlib.no/netlib/lapack/:lapack \
		ftp://ftp.netlib.no/netlib/lapack/timing/:lapack_tmg
DISTFILES=	GotoBLAS2-${GOTOBLAS2VER}_bsd.tar.gz lapack-3.1.1.tgz:lapack large.tgz:lapack_tmg timing.tgz:lapack_tmg
EXTRACT_ONLY=   ${GOTOBLAS2_SRCFILE}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A fast implementation of Basic Linear Algebra Subprograms

DIST_SUBDIR=	gotoblas
GOTOBLAS2VER=	1.13
GOTOBLAS2_SRCFILE=	GotoBLAS2-${GOTOBLAS2VER}_bsd.tar.gz
LAPACK_SRCFILE=	lapack-3.1.1.tgz
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/GotoBLAS2

USE_PERL5_BUILD=	yes
USE_FORTRAN=   yes
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
GOTOLIBS=	libgoto2 libgoto2p
GOTOFILES=	${GOTOLIBS:S|$|.so|} ${GOTOLIBS:S|$|.so.1|} ${GOTOLIBS:S|$|.a|}
PLIST_FILES=	${GOTOFILES:S|^|lib/|}

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils

.if ${ARCH} == "amd64" || ${ARCH} == "alpha" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
MAKE_FLAGS+=	BINARY64=1
.else
MAKE_FLAGS+=	BINARY32=1
.endif

.if defined(WITH_INTERFACE64)
MAKE_FLAGS+=	INTERFACE64=1
.endif

.if defined(WITH_GFORTRAN)
MAKE_FLAGS+=	F_COMPILER=GFORTRAN
.elif defined(WITH_G77)
MAKE_FLAGS+=	F_COMPILER=G77
.elif defined(WITH_G95)
MAKE_FLAGS+=	F_COMPILER=G95
.elif defined(WITH_IFORT)
MAKE_FLAGS+=	F_COMPILER=INTEL
.elif defined(WITH_PGF77)
MAKE_FLAGS+=	F_COMPILER=PGI
.elif defined(WITH_PATHF90)
MAKE_FLAGS+=	F_COMPILER=PATHF90
.elif defined(WITH_XLF)
MAKE_FLAGS+=	F_COMPILER=IBM
.endif

pre-build::
	@${ECHO_CMD} "****"
	@${ECHO_CMD} "You can choose FORTRAN compiler" \
		"by using the following knobs:"
	@${ECHO_CMD} "   WITH_GFORTRAN=yes (gfortran; default)"
	@${ECHO_CMD} "   WITH_G77=yes (g77)"
	@${ECHO_CMD} "   WITH_G95=yes (g95)"
	@${ECHO_CMD} "   WITH_IFORT=yes (ifort)"
	@${ECHO_CMD} "   WITH_PGF77=yes (pgf77)"
	@${ECHO_CMD} "   WITH_PATHF90=yes (pathf90)"
	@${ECHO_CMD} "   WITH_XLF=yes (xlf)"
	@${ECHO_CMD} "   WITH_INTERFACE64=yes (for using 64-bit integer interface)"
	@${ECHO_CMD} "- Note that if the specified compiler does not exist" \
		"on your system, build will fail."
	@${ECHO_CMD} "- None is specified, gfortran will be used."
	@${ECHO_CMD} "****"

post-patch:
	${REINPLACE_CMD} -e "s+%%FC%%+${FC}+" -e "s+%%CC%%+${CC}+" ${WRKSRC}/Makefile.rule
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/Makefile.system
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/Makefile.rule
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/Makefile.tail
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/driver/level3/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/driver/others/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/exports/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/interface/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/kernel/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/kernel/Makefile.L3
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/lapack/laswp/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" ${WRKSRC}/reference/Makefile

do-build:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${LAPACK_SRCFILE} ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${LARGE_FILE} ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${TIMING_FILE} ${WRKSRC}
	${MKDIR} ${WRKDIR}/lib
	cd ${WRKSRC} && ${GMAKE} ${MAKE_FLAGS} USE_THREAD=1 DYNAMIC_ARCH=1
	cd ${WRKSRC}/exports && ${GMAKE} ${MAKE_FLAGS} USE_THREAD=1 DYNAMIC_ARCH=1
	${INSTALL_DATA} ${WRKSRC}/libgoto2.a ${WRKDIR}/lib/libgoto2p.a
	${INSTALL_DATA} ${WRKSRC}/libgoto2.so ${WRKDIR}/lib/libgoto2p.so

	cd ${WRKSRC} && ${GMAKE} clean
	cd ${WRKSRC}/exports && ${GMAKE} clean
	cd ${WRKSRC} && ${GMAKE} ${MAKE_FLAGS} USE_THREAD=0 DYNAMIC_ARCH=1
	cd ${WRKSRC}/exports && ${GMAKE} ${MAKE_FLAGS} USE_THREAD=0 DYNAMIC_ARCH=1
	${INSTALL_DATA} ${WRKSRC}/libgoto2.a ${WRKDIR}/lib/libgoto2.a
	${INSTALL_DATA} ${WRKSRC}/libgoto2.so ${WRKDIR}/lib/libgoto2.so

benchmark:
	cd ${WRKSRC}/ && \
		${GMAKE} ${MAKE_FLAGS} hpl
	cd ${WRKSRC}/benchmark && \
		${GMAKE} ${MAKE_FLAGS} dlinpack.goto

do-install:
	cd ${WRKDIR}/lib/ && \
	${INSTALL_DATA} ${GOTOLIBS:S|$|.a|} ${PREFIX}/lib/ && \
	${INSTALL_DATA} ${GOTOLIBS:S|$|.so|} ${PREFIX}/lib/
	cd ${PREFIX}/lib/ && \
	for i in ${GOTOLIBS:S|$|.so|}; do \
		${LN} -sf $$i $$i.1;done

.include <bsd.port.post.mk>
