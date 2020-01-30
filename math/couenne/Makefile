# $FreeBSD$

PORTNAME=	couenne
DISTVERSIONPREFIX=	releases/
DISTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convex Over and Under Envelopes for NonliNear Estimation

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Couenne/LICENSE

LIB_DEPENDS=	libbonmin.so:math/bonmin \
		libCbc.so:math/coinmp \
		libipopt.so:math/ipopt

USES=		blaslapack:netlib fortran gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	Couenne
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
