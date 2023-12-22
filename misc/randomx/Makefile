PORTNAME=	randomx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Proof of work algorithm based on random code execution
WWW=		https://github.com/tevador/RandomX

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	tevador
GH_PROJECT=	RandomX

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_TARGET=

PLIST_FILES=	include/randomx.h \
		lib/librandomx.so

post-test: # run tests
	@cd ${BUILD_WRKSRC} && ./randomx-tests

.include <bsd.port.mk>
