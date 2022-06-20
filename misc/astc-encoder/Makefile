PORTNAME=	astc-encoder
DISTVERSION=	3.7
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
CMAKE_TESTING_ON=	UNITTEST # tests fail to build, see https://github.com/ARM-software/astc-encoder/issues/346

LDFLAGS+=	-pthread

PLIST_FILES=	bin/astcenc-native

post-patch: # workaround for https://github.com/ARM-software/astc-encoder/issues/345
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -e 's|astcenc/|bin/|' \
			Test/testlib/encoder.py \
			Test/astc_minify_test.sh \
			Test/astc_update_ref.sh \
			Test/astc_minify_test.sh \
			Test/astc_test_competitive.py

.include <bsd.port.mk>
