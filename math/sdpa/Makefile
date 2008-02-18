# New ports collection makefile for:    sdpa
# Date created:                         October 4 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpa
PORTVERSION=	7.0.5
CATEGORIES=	math
MASTER_SITES=	http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTFILES=	${PORTNAME}.${PORTVERSION}.src.tar.gz ${PORTNAME}.${PORTVERSION}.manual.pdf
DIST_SUBDIR=	sdpa
EXTRACT_ONLY=	${PORTNAME}.${PORTVERSION}.src.tar.gz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SDPA(SemiDefinite Programming Algorithm) Very efficent SDP Solver

.include <bsd.port.pre.mk>

USE_FORTRAN=	yes
CONFIGURE_ENV+=	F77="${F77}"
GNU_CONFIGURE=	yes
LIB_DEPENDS+=	spooles:${PORTSDIR}/math/spooles

USE_BLAS?=	reference

.if exists(${LOCALBASE}/lib/libgoto.so)
USE_BLAS=     gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
USE_BLAS=     atlas
.endif

. if ${USE_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${USE_BLAS} == gotoblas
LIB_DEPENDS+=	goto:${PORTSDIR}/math/gotoblas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lgotop
LAPACK=		-lgotop -llapack
.elif ${USE_BLAS} == atlas
LIB_DEPENDS+=   atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas -lptcblas -latlas_r
LAPACK=		-lalapack_r
.endif

CONFIGURE_ARGS+=--with-blas="-L${LOCALBASE}/lib ${BLAS}" --with-lapack="-L${LOCALBASE}/lib ${LAPACK}" --with-system-spooles
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/spooles" CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/spooles" CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/spooles" LDFLAGS="-L${LOCALBASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpa ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTNAME}.${PORTVERSION}.manual.pdf
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
