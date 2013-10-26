# Created by: Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
# $FreeBSD$

PORTNAME=	lapacke
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	NL
MASTER_SITE_SUBDIR=	lapack
DISTNAME=	lapack-${PORTVERSION}
DISTFILES=	${DISTNAME}.tgz lapacke.tgz
DIST_SUBDIR=	lapack

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Standard C language APIs for LAPACK

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USE_FORTRAN=	yes

OPTIONS_DEFINE=	PROFILE XLAPACKE
PROFILE_DESC=	Build a profiling library
XLAPACKE_DESC=	Install interfaces to XLAPACK

NO_STAGE=	yes
.include <bsd.port.pre.mk>

LAPACKE_SVERSION=	1
LAPACKE_LIBNAME=	lapacke
LAPACKE_LIBNAME_TMG=	lapacke_tmg
MAKE_ENV+=		"SHLIB_MAJOR=${LAPACKE_SVERSION}" \
			"LAPACKE_LIBNAME=${LAPACKE_LIBNAME}" \
			"LAPACKE_LIBNAME_TMG=${LAPACKE_LIBNAME_TMG}"
.if ${PORT_OPTIONS:MXLAPACKE}
XLAPACKE_LIBNAME=	xlapacke
MAKE_ENV+=		"XLAPACKE_LIBNAME=${XLAPACKE_LIBNAME}"
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
WRKSRC_LEGACY =	${WRKDIR}/lapacke

.if exists(${LOCALBASE}/lib/libgoto2p.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == "reference"
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas \
		lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == "gotoblas"
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
LIB_DEPENDS+=	goto2p.1:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
.elif ${WITH_BLAS} == "atlas"
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
.endif
.if ${PORT_OPTIONS:MXLAPACKE}
LIB_DEPENDS+=		xlapack.4:${PORTSDIR}/math/xlapack
.endif

LDFLAGS+=	-L${LOCALBASE}/lib

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README
.endif
PLIST_FILES=	include/lapacke.h \
		include/lapacke_utils.h \
		lib/lib${LAPACKE_LIBNAME}.a \
		lib/lib${LAPACKE_LIBNAME_TMG}.a \
		lib/lib${LAPACKE_LIBNAME}.so \
		lib/lib${LAPACKE_LIBNAME_TMG}.so \
		lib/lib${LAPACKE_LIBNAME}.so.${LAPACKE_SVERSION} \
		lib/lib${LAPACKE_LIBNAME_TMG}.so.${LAPACKE_SVERSION}
.if ${PORT_OPTIONS:MXLAPACKE}
PLIST_FILES+=	lib/lib${XLAPACKE_LIBNAME}.a \
		lib/lib${XLAPACKE_LIBNAME}.so \
		lib/lib${XLAPACKE_LIBNAME}.so.${LAPACKE_SVERSION}
.endif

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE =	you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE	=	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/lib${LAPACKE_LIBNAME}_p.a \
		lib/lib${LAPACKE_LIBNAME_TMG}_p.a
.if ${PORT_OPTIONS:MXLAPACKE}
PLIST_FILES+=	lib/lib${XLAPACKE_LIBNAME}_p.a
.endif
.else
MAKE_ENV+=	NO_PROFILE=
.endif

post-extract:
	@${CP} -r ${WRKSRC_LEGACY}/testing ${WRKSRC}/.

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" -type f |\
		${XARGS} ${REINPLACE_CMD} -e 's;$$(ARCH);$$(ARCH_);g'
	@${REINPLACE_CMD} -e 's;%%CC%%;${CC};g' \
			  -e 's;%%CFLAGS%%;${CFLAGS};g' \
			  -e 's;%%LDFLAGS%%;${LDFLAGS};g' \
			  -e 's;%%AR%%;${AR};g' \
			  -e 's;%%RANLIB%%;${RANLIB};g' \
			  -e 's;%%BLAS%%;${BLAS};g' \
			  -e 's;%%LAPACK%%;${LAPACK};g' \
			  -e 's;%%LAPACKE_LIBNAME%%;${LAPACKE_LIBNAME};g' \
				${WRKSRC}/make.inc
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	@${MKDIR} ${WRKSRC}/lib
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/lib/Makefile
	@${MKDIR} ${WRKSRC}/libtmg
	@${CP} ${FILESDIR}/Makefile.libtmg ${WRKSRC}/libtmg/Makefile

	@${REINPLACE_CMD} -e 's;%%XLAPACKE%%;;g' \
			-e 's;%%__XLAPACKE%%;\#;g' \
			${WRKSRC}/lib/Makefile

.if ${PORT_OPTIONS:MXLAPACKE}
	@${MKDIR} ${WRKSRC}/libx
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/libx/Makefile
	@${REINPLACE_CMD} -e 's;%%__XLAPACKE%%;;g' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's;LAPACKE_LIBNAME;XLAPACKE_LIBNAME;g' \
			-e 's;%%XLAPACKE%%;\#;g' \
			-e 's;%%__XLAPACKE%%;;g' \
			${WRKSRC}/libx/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

check regression-test test: build
	@${CP} ${WRKSRC}/lib/lib${LAPACKE_LIBNAME}.a ${WRKSRC}/.
	@${ECHO_CMD} "Testing static lapacke library"
	@(cd ${WRKSRC}/testing; ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS})
	@${CAT} ${WRKSRC}/testing/interface/*.out

.include <bsd.port.post.mk>
