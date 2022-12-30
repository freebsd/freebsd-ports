PORTNAME=	onnx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange
WWW=		https://onnx.ai/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake:testing python:build

USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_ONNX_PYTHON
CMAKE_TESTING_ON=	ONNX_BUILD_TESTS
CMAKE_TESTING_TARGET=

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

post-test:
	cd ${BUILD_WRKSRC} && ./onnx_gtests

.include <bsd.port.mk>
