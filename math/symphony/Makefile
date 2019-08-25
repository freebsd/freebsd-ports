# $FreeBSD$

PORTNAME=	symphony
DISTVERSIONPREFIX=	releases/
DISTVERSION=	5.6.17
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver and development framework for mixed-integer linear programs

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/SYMPHONY/LICENSE

LIB_DEPENDS=	libCbc.so:math/coinmp

USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	SYMPHONY
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
