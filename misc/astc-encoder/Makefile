PORTNAME=	astc-encoder
DISTVERSION=	3.7-92
DISTVERSIONSUFFIX=	-g50f5f8f
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texture compressor for Adaptive Scalable Texture Compression format

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_TUPLE=	google:googletest:703bd9c:googletest/Source/GoogleTest

CMAKE_OFF=	UNITTEST
CMAKE_TESTING_ON=	UNITTEST # tests fail to build, see https://github.com/ARM-software/astc-encoder/issues/349

LDFLAGS+=	-pthread

PLIST_FILES=	bin/astcenc-native

.include <bsd.port.mk>
