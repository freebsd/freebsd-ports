# New ports collection makefile for:	hutiter
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	hutiter
PORTVERSION=	5.3.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/src/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	HUTIter library for use in the ELMER FEM package

LIB_DEPENDS=	arpack.1:${PORTSDIR}/math/arpack

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
LAPACK=		-llapack
.endif

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%FC%%|${FC}|' ${WRKSRC}/configure.in

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259
CONFIGURE_ENV+=	FC=${FC} F77=${FC}
ALL_TARGET=

PLIST_FILES=	include/huti_defs.h include/huti_fdefs.h lib/libhuti.a

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC

post-configure:
	@${REINPLACE_CMD} -e 's+-O +-O -fPIC +g;' ${WRKSRC}/src/Makefile

.endif

.include <bsd.port.post.mk>
