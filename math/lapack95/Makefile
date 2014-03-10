# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lapack95
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	NL
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	lapack95

MAINTAINER=	maho@FreeBSD.org
COMMENT=	LAPACK95, Fortran90/95 wrapper for LAPACK

USES=		fortran
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/LAPACK95

MAKE_JOBS_UNSAFE=yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

.if exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == atlas
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	make.inc EXAMPLES1 EXAMPLES2
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%BLAS%%|${BLAS}|g ; \
		 s|%%FC%%|${FC}|g ; \
		 s|%%FFLAGS%%|${FFLAGS} $${PICFLAG}|g ; \
		 s|%%LAPACK%%|${LAPACK}|g ; \
		 s|%%LDFLAGS%%|${LDFLAGS}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's|ranlib|${RANLIB}|g ; \
		 s|ar cr|${AR} cr|g' \
		${WRKSRC}/SRC/makefile \
		${WRKSRC}/TESTING/makefile \
		${WRKSRC}/EXAMPLES1/makefile*
	@${CP} -r ${WRKSRC} ${WRKSRC}_SHARED

do-build:
	@cd ${WRKSRC}/SRC; ${SETENV} ${MAKE_ENV} PICFLAG= \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} single_double_complex_dcomplex
	@cd ${WRKSRC}_SHARED/SRC; ${SETENV} ${MAKE_ENV} PICFLAG=${PICFLAG} \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} single_double_complex_dcomplex
	@cd ${WRKSRC}_SHARED ; ${LD} -Bshareable -o liblapack95.so.1 -x -soname \
		liblapack95.so.1 --whole-archive lapack95.a

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lapack95.a ${PREFIX}/lib/liblapack95.a
	@${INSTALL_DATA} ${WRKSRC}_SHARED/liblapack95.so.1 ${PREFIX}/lib
	@${LN} -sf liblapack95.so.1 ${PREFIX}/lib/liblapack95.so
	@${MKDIR} ${PREFIX}/lib/lapack95_modules
	@${INSTALL_DATA} ${WRKSRC}_SHARED/lapack95_modules/*.mod ${PREFIX}/lib/lapack95_modules
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
