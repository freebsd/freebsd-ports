PORTNAME=	libwebm
DISTVERSIONPREFIX=	libwebm-
DISTVERSION=	1.0.0.32
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebM video format
WWW=		https://www.webmproject.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	webmproject
GH_TUPLE=	google:googletest:release-1.11.0:gtest/../googletest

CMAKE_ON=	ENABLE_IWYU \
		ENABLE_WEBM_PARSER \
		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	ENABLE_TESTS # it's not clear how to run tests, some test executables show failures when run

.include <bsd.port.mk>
