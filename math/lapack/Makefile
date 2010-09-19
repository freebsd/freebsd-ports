# New ports collection makefile for:    lapack
# Date created:         2 July 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	lapack
PORTVERSION=	3.2.2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/ \
		http://netlib.org/lapack/ \
		http://scicomp.ewha.ac.kr/netlib/lapack/ \
		http://service-spi.web.cern.ch/service-spi/external/tarFiles/
DISTFILES=	lapack-${PORTVERSION}.tgz manpages-3.2.0.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A library of Fortran 77 subroutines for linear algebra

LIB_DEPENDS=	blas.2:${PORTSDIR}/math/blas

USE_FORTRAN=	yes
DIST_SUBDIR=	lapack
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

MAKE_JOBS_SAFE=	yes
MANSRC=${WRKDIR}/lapack-3.2.0
WRKSRC_SHARED=${WRKSRC}_shared
FFLAGS_SHARED=${FPIC}
.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
WRKSRC_PROFILE=${WRKSRC}_profile
FFLAGS_PROFILE=-pg
PLIST_SUB+=	PROFILE=""
.else
PLIST_SUB+=	PROFILE="@comment "
.endif

SVERSION=4
BLAS?=	-L${LOCALBASE}/lib -lblas
RANLIB=	${LOCALBASE}/bin/ranlib
AR=	${LOCALBASE}/bin/ar

pre-fetch:
	@${ECHO} "You can override F77 and FFLAGS on the command line."

.include "${FILESDIR}/manpages"

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
.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
	@${REINPLACE_CMD} -e 's,%%EXTRAFLAGS%%,${FFLAGS_PROFILE},g' \
				${WRKSRC_PROFILE}/make.inc
.endif

do-build:
	@${ECHO_CMD} "Building static lapack library"
	${MAKE} -C ${WRKSRC} ${.MAKEFLAGS} ${_MAKE_JOBS} ARCH="${AR}"
	@${ECHO_CMD} "Building shared lapack library"
	${MAKE} -C ${WRKSRC_SHARED} ${.MAKEFLAGS} ${_MAKE_JOBS} ARCH="${AR}"
.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
	@${ECHO_CMD} "Building profile lapack library"
	${MAKE} -C ${WRKSRC_PROFILE} ${.MAKEFLAGS} ${_MAKE_JOBS} ARCH="${AR}"
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
.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
	${INSTALL_DATA} ${WRKSRC_PROFILE}/lib${lib}.a ${PREFIX}/lib/lib${lib}_p.a
.endif
.endfor
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[a-c]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[d-l]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[m-s]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[t-z]*.l ${PREFIX}/man/manl

regression-test check test: build
	@${ECHO_CMD} "Testing static lapack library"
	${MAKE} -C ${WRKSRC}/TESTING ${.MAKEFLAGS} ARCH="${AR}"

.include <bsd.port.post.mk>
