PORTNAME=	onnx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.2
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange
WWW=		https://onnx.ai/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libprotobuf.so:devel/protobuf

USES=		cmake:testing compiler:c++17-lang python:build

USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_ONNX_PYTHON
CMAKE_TESTING_ON=	ONNX_BUILD_TESTS
CMAKE_TESTING_TARGET=

CXXFLAGS+=	-Dstat64=stat

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

post-test:
	cd ${BUILD_WRKSRC} && ./onnx_gtests

.include <bsd.port.mk>
