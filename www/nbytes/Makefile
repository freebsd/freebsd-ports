PORTNAME=	nbytes
PORTVERSION=	0.1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library of byte handling functions extracted from Node.js core
WWW=		https://github.com/nodejs/nbytes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++20-lang

CMAKE_OFF=	NBYTES_DEVELOPMENT_CHECKS \
		NBYTES_ENABLE_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	NBYTES_ENABLE_TESTING

USE_GITHUB=	yes
GH_ACCOUNT=	nodejs

# Remove after 14.3-RELEASE EoL (expected 2026-06-30)
.if !exists(/usr/bin/clang-scan-deps)
USES+=         llvm:build
.endif

.include <bsd.port.mk>
