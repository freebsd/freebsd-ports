# New ports collection makefile for:	hutiter
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	hutiter
PORTVERSION=	5.2.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HUTIter library for use in the ELMER FEM package

BUILD_DEPENDS=	${FC}:${PORTSDIR}/lang/gfortran	\
		${LOCALBASE}/lib/libblas.a:${PORTSDIR}/math/elmer-mathlibs	 \
		${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/elmer-mathlibs	 \
		${LOCALBASE}/lib/libarpack.a:${PORTSDIR}/math/elmer-mathlibs

USE_GCC=	4.1+

FC=	${LOCALBASE}/bin/gfortran41
F77=	${FC}
WITH_FORTRAN=	yes
CONFIGURE_ENV+=	FC=${FC} F77=${FC}
GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	include/huti_defs.h include/huti_fdefs.h lib/libhuti.a

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC

post-configure:
	@${REINPLACE_CMD} -e 's+-O +-O -fPIC +g;' ${WRKSRC}/src/Makefile

.endif

.include <bsd.port.post.mk>
