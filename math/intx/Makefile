PORTNAME=	intx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	math

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extended precision integer library
WWW=		https://github.com/chfast/intx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang
USE_GITHUB=	yes
GH_ACCOUNT=	chfast

CMAKE_OFF=	INTX_TESTING
NO_ARCH=	yes

.include <bsd.port.mk>
