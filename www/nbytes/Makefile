PORTNAME=	nbytes
PORTVERSION=	0.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library of byte handling functions extracted from Node.js core
WWW=		https://github.com/nodejs/nbytes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++20-lang

CMAKE_OFF=	BUILD_TESTING \
		NBYTES_DEVELOPMENT_CHECKS
CMAKE_ON=	BUILD_SHARED_LIBS

USE_GITHUB=	yes
GH_ACCOUNT=	nodejs

# Remove after 13.5-RELEASE EoL
.if !exists(/usr/bin/clang-scan-deps)
USES+=		llvm:build
.endif

.include <bsd.port.mk>
