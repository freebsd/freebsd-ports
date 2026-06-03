PORTNAME=	wslay
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.1.1-22
DISTVERSIONSUFFIX=	-g45d2258
PORTREVISION=	1
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C WebSocket library
WWW=		https://github.com/tatsuhiro-t/wslay

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cunit>0:devel/cunit

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	tatsuhiro-t

CMAKE_ON=	WSLAY_SHARED
CMAKE_OFF=	WSLAY_STATIC

CMAKE_TESTING_ON=	WSLAY_TESTS

post-extract:
	${CP} ${FILESDIR}/wslay.pc.cmake.in ${WRKSRC}

.include <bsd.port.mk>
