# $FreeBSD$

PORTNAME=	cgl
DISTVERSIONPREFIX=	releases/
DISTVERSION=	0.59.10
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of cut generators for COIN-OR packages that use cuts

LICENSE=	EPL

LIB_DEPENDS=	libblas.so:math/blas \
		libClp.so:math/clp \
		liblapack.so:math/lapack

USES=		compiler:c++11-lang gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Cgl
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libCgl.so.*

.include <bsd.port.mk>
