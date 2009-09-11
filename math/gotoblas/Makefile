# Ports collection makefile for: gotoblas
# Date created:         20070203
# Whom:			Sato Hiroki <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gotoblas
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	#empty
DISTNAME=	GotoBLAS-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The fastest implementation of the Basic Linear Algebra Subroutines

USE_GMAKE=	yes
USE_LDCONFIG=	yes
RESTRICTED=	Redistribution not permitted
MANUAL_PACKAGE_BUILD=	Please obtain the source code manyally from http://www.tacc.utexas.edu/resources/software/
WRKSRC=		${WRKDIR}/GotoBLAS
PLIST_FILES=	lib/libgoto.a \
		lib/libgoto.so \
		lib/libgoto.so.1 \
		lib/libgotop.a \
		lib/libgotop.so \
		lib/libgotop.so.1

USE_PERL5=	yes

.include <bsd.port.pre.mk>

USE_FORTRAN=   yes
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils

.if ${ARCH} == "amd64" || ${ARCH} == "alpha" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
MAKE_FLAGS+=	BINARY64=1
.else
MAKE_FLAGS+=	BINARY32=1
.endif

.if defined(WITH_INTERFACE64)
MAKE_FLAGS+=	INTERFACE64=1
.endif

.if defined(WITH_G77)
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

MAKE_FLAGS_SMP=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

pre-everything::
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

.if !defined(PACKAGE_BUILDING) && !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
do-fetch:
	@${ECHO_CMD} "You need to fetch ${DISTFILES} from:"
	@${ECHO_CMD} "http://www.tacc.utexas.edu/resources/software/software.php"
	@${ECHO_CMD} "and put it to ${DISTDIR}."
.endif

#Honor FC and CC, but this makes Makefile.rule bit dirtier
pre-build:
	@${REINPLACE_CMD} -e "s+%%FC%%+${FC}+" -e "s+%%CC%%+${CC}+" ${WRKSRC}/Makefile.rule

do-build:
	${MKDIR} ${WRKDIR}/lib
	cd ${WRKSRC} && \
		${GMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/exports \
		&& ${GMAKE} ${MAKE_FLAGS} so
	${INSTALL_DATA} ${WRKSRC}/libgoto-r${PORTVERSION}.a \
		${WRKDIR}/lib/libgoto.a
	${INSTALL_DATA} ${WRKSRC}/libgoto-r${PORTVERSION}.so \
		${WRKDIR}/lib/libgoto.so.1
	cd ${WRKSRC} && ${GMAKE} clean
	cd ${WRKSRC} && \
		${GMAKE} ${MAKE_FLAGS_SMP} ${MAKE_FLAGS} SMP=1
	cd ${WRKSRC}/exports && \
		${GMAKE} ${MAKE_FLAGS_SMP} ${MAKE_FLAGS} SMP=1 so
	${INSTALL_DATA} ${WRKSRC}/libgotop-r${PORTVERSION}.a \
		${WRKDIR}/lib/libgotop.a
	${INSTALL_DATA} ${WRKSRC}/libgotop-r${PORTVERSION}.so \
		${WRKDIR}/lib/libgotop.so.1

do-install:
	${INSTALL_DATA} ${WRKDIR}/lib/libgoto.a ${PREFIX}/lib/libgoto.a
	${INSTALL_DATA} ${WRKDIR}/lib/libgoto.so.1 ${PREFIX}/lib/libgoto.so.1
	${INSTALL_DATA} ${WRKDIR}/lib/libgotop.a ${PREFIX}/lib/libgotop.a
	${INSTALL_DATA} ${WRKDIR}/lib/libgotop.so.1 ${PREFIX}/lib/libgotop.so.1
	cd ${PREFIX}/lib && ${LN} -s -f libgoto.so.1 libgoto.so
	cd ${PREFIX}/lib && ${LN} -s -f libgotop.so.1 libgotop.so

.include <bsd.port.post.mk>
