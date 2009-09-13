# New ports collection makefile for:    lapack95
# Date created:                         5 Feb 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lapack95
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack95/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	lapack95

MAINTAINER=	maho@FreeBSD.org
COMMENT=	LAPACK95, Fortran90/95 wrapper for LAPACK

.include <bsd.port.pre.mk>
.if ${ARCH} == "sparc64"
PICFLAG?=       -fPIC
.else
PICFLAG?=       -fpic
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

USE_FORTRAN=	yes
WRKSRC=		${WRKDIR}/LAPACK95
FORTRAN_FIXED=
FORTRAN_FREE=#	-free
FFLAGS=#	-O3 -tpp7 -xKW -Vaxlib #for ifc

post-patch:
	@${MKDIR} ${WRKSRC}_SHARED ; ${CP} -r ${WRKSRC}/* ${WRKSRC}_SHARED

pre-build:
	@${REINPLACE_CMD} -e 's,%%FC%%,${FC},g ; \
		 s,%%FORTRAN_FIXED%%,${FORTRAN_FIXED},g ; \
		 s,%%FORTRAN_FREE%%,${FORTRAN_FREE},g ; \
		 s,%%FFLAGS%%,${FFLAGS},g ; \
		 s,%%BLAS%%,${BLAS},g ; \
		 s,%%LAPACK%%,${LAPACK},g ; \
		 s,%%PREFIX%%,${PREFIX},g ; \
		 s,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's,%%FC%%,${FC},g ; \
		 s,%%FORTRAN_FIXED%%,${FORTRAN_FIXED},g ; \
		 s,%%FORTRAN_FREE%%,${FORTRAN_FREE},g ; \
		 s,%%FFLAGS%%,${FFLAGS} ${PICFLAG},g ; \
		 s,%%BLAS%%,${BLAS},g ; \
		 s,%%LAPACK%%,${LAPACK},g ; \
		 s,%%PREFIX%%,${PREFIX},g ; \
		 s,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}_SHARED/make.inc
do-build:
	cd ${WRKSRC}/SRC; ${MAKE} single_double_complex_dcomplex
	cd ${WRKSRC}_SHARED/SRC; ${MAKE} single_double_complex_dcomplex
	cd ${WRKSRC}_SHARED ; ld -Bshareable -o liblapack95.so.1 -x -soname liblapack95.so.1 --whole-archive lapack95.a
do-install:
	${INSTALL_DATA} ${WRKSRC}/lapack95.a ${PREFIX}/lib/liblapack95.a
	${INSTALL_DATA} ${WRKSRC}_SHARED/liblapack95.so.1 ${PREFIX}/lib
	${LN} -sf liblapack95.so.1 ${PREFIX}/lib/liblapack95.so

	${MKDIR} ${PREFIX}/lib/lapack95_modules
	${INSTALL_DATA} ${WRKSRC}_SHARED/lapack95_modules/*.mod ${PREFIX}/lib/lapack95_modules
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/EXAMPLES1
	@${MKDIR} ${EXAMPLESDIR}/EXAMPLES2
	${CP}	${WRKSRC}/make.inc ${EXAMPLESDIR}
	${TAR} cf - -C ${WRKSRC}/EXAMPLES1 . | ${TAR} xf - -C ${EXAMPLESDIR}/EXAMPLES1
	${TAR} cf - -C ${WRKSRC}/EXAMPLES2 . | ${TAR} xf - -C ${EXAMPLESDIR}/EXAMPLES2
	${FIND} ${EXAMPLESDIR}/EXAMPLES1 | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${EXAMPLESDIR}/EXAMPLES1 -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${EXAMPLESDIR}/EXAMPLES2 | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${EXAMPLESDIR}/EXAMPLES2 -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.post.mk>
