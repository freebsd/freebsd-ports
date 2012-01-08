# New ports collection makefile for:    lapack
# Date created:         2 July 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	lapack
PORTVERSION=	3.4.0
CATEGORIES=	math
MASTER_SITES=	NL
MASTER_SITE_SUBDIR=	lapack
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	lapack

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A library of Fortran 77 subroutines for linear algebra

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	blas.2:${PORTSDIR}/math/blas

USE_FORTRAN=	yes
USE_LDCONFIG=	yes

OPTIONS=	PROFILE "Build and install profiling libraries" Off \
		DOXYGEN "Install Doxygen to build manpages" Off

.include <bsd.port.pre.mk>

.if defined(WITH_DOXYGEN)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

.if ${ARCH} == "sparc64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

MAKE_JOBS_SAFE=	yes
WRKSRC_SHARED=${WRKSRC}_shared
FFLAGS_SHARED=${FPIC}
.if defined(WITH_PROFILE)
.if defined(WITHOUT_PROFILE)
IGNORE =	you have defined both WITH_PROFILE and WITHOUT_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE=	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
WRKSRC_PROFILE=${WRKSRC}_profile
FFLAGS_PROFILE=-pg
PLIST_SUB+=	PROFILE=""
.else
PLIST_SUB+=	PROFILE="@comment "
.endif

SVERSION=4
BLAS?=	-L${LOCALBASE}/lib -lblas

.if !defined(WITH_DOXYGEN)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} manpages-3.2.0.tgz
MANSRC=		${WRKDIR}/lapack-3.2.0/manpages/man/manl
.include "${FILESDIR}/manpages"
MANL=		${LAPACK_MAN}
MANDIR=		${PREFIX}/man/manl
.else
.include "${FILESDIR}/manpages_doxygen"
MANSRC=		${WRKSRC}/DOCS/man/man3
MAN3=		${LAPACK_MAN}
MANDIR=		${PREFIX}/man/man3
.endif

pre-fetch:
	@${ECHO} "You can override F77 and FFLAGS on the command line."

post-patch:
	@${MV} ${WRKSRC}/INSTALL/make.inc.gfortran ${WRKSRC}/make.inc
	${REINPLACE_CMD} -Ee \
		's,\( *cd ([^ ;]+) *; *\$$\(MAKE\) *([[:alnum:]]*) *\),${MAKE} -C \1 ${_MAKE_JOBS} \2,' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -Ee \
		's,cd ([^ ;]+) *; *\$$\(MAKE\) *([[:alnum:]]*) *,${MAKE} -C \1 ${_MAKE_JOBS} \2,' \
		${WRKSRC}/TESTING/Makefile
	@${REINPLACE_CMD} -e 's;%%F77%%;${F77};g' \
			  -e 's;%%FFLAGS%%;${FFLAGS};g' \
			  -e 's;%%LDFLAGS%%;${LDFLAGS};g' \
			  -e 's;%%RANLIB%%;${RANLIB};g' \
			  -e 's;%%BLAS%%;${BLAS};g' \
				${WRKSRC}/make.inc
	@${CP} -r ${WRKSRC} ${WRKSRC_SHARED}
.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
	@${CP} -r ${WRKSRC} ${WRKSRC_PROFILE}
.endif
	@${REINPLACE_CMD} -e 's,%%EXTRAFLAGS%%,,g' \
				${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's,%%EXTRAFLAGS%%,${FFLAGS_SHARED},g' \
				${WRKSRC_SHARED}/make.inc
.if defined(WITH_PROFILE)
	@${REINPLACE_CMD} -e 's,%%EXTRAFLAGS%%,${FFLAGS_PROFILE},g' \
				${WRKSRC_PROFILE}/make.inc
.endif

do-build:
	@${ECHO_CMD} "Building static lapack library"
	${MAKE} -C ${WRKSRC} ${.MAKEFLAGS} ${_MAKE_JOBS} ARCH="${AR}"
	@${ECHO_CMD} "Building shared lapack library"
	${MAKE} -C ${WRKSRC_SHARED} ${.MAKEFLAGS} ${_MAKE_JOBS} ARCH="${AR}"
.if defined(WITH_PROFILE)
	@${ECHO_CMD} "Building profile lapack library"
	${MAKE} -C ${WRKSRC_PROFILE} ${.MAKEFLAGS} ${_MAKE_JOBS} ARCH="${AR}"
.endif
.if defined(WITH_DOXYGEN)
	${MAKE} -C ${WRKSRC} ${.MAKEFLAGS} ${_MAKE_JOBS} ARCH="${AR}" man
.endif

post-build:
.for lib in lapack tmglib
	cd ${WRKSRC_SHARED} ; ${FC} ${FFLAGS} ${FFLAGS_SHARED} ${LDFLAGS} -shared \
	-o lib${lib}.so.${SVERSION} -Wl,-x -Wl,-soname,lib${lib}.so.${SVERSION} \
	-Wl,--whole-archive lib${lib}.a -Wl,--no-whole-archive
.endfor

do-install:
.for lib in lapack tmglib
	${INSTALL_DATA} ${WRKSRC}/lib${lib}.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC_SHARED}/lib${lib}.so.${SVERSION} ${PREFIX}/lib
	${LN} -sf lib${lib}.so.${SVERSION} ${PREFIX}/lib/lib${lib}.so
.if defined(WITH_PROFILE)
	${INSTALL_DATA} ${WRKSRC_PROFILE}/lib${lib}.a ${PREFIX}/lib/lib${lib}_p.a
.endif
.endfor
	@(cd ${MANSRC} && ${INSTALL_MAN} ${LAPACK_MAN} ${MANDIR})

regression-test check test: build
	@${ECHO_CMD} "Testing static lapack library"
	${MAKE} -C ${WRKSRC}/TESTING ${.MAKEFLAGS} ARCH="${AR}"

.include <bsd.port.post.mk>
