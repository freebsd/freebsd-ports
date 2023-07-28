PORTNAME=	libuvc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform library for USB video devices
WWW=		https://libuvc.github.io/libuvc/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing jpeg pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_EXAMPLE
CMAKE_TESTING_ON=	BUILD_TEST # tests fail to compile, see https://github.com/libuvc/libuvc/issues/254

.include <bsd.port.mk>
