PORTNAME=	onnx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.1
PORTREVISION=	1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange
WWW=		https://onnx.ai \
		https://github.com/onnx/onnx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libprotobuf.so:devel/protobuf

USES=		cmake:testing compiler:c++17-lang python:build

USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ONNX_BUILD_PYTHON
CMAKE_TESTING_ON=	ONNX_BUILD_TESTS
CMAKE_TESTING_TARGET=

CXXFLAGS+=	-Dstat64=stat

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

post-test:
	cd ${BUILD_WRKSRC} && ./onnx_gtests

# tests as of 1.19.1: (NOTE: tests require static build, so the CMAKE_ON=BUILD_SHARED_LIBS needs to be commented out)
# [==========] 95 tests from 13 test suites ran. (18 ms total)
# [  PASSED  ] 95 tests.

.include <bsd.port.mk>
