# $FreeBSD$

PORTNAME=	onnx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0.20191021
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++11-lang python:build
USE_GITHUB=	yes
GH_TAGNAME=	3ea3b0e0 # repo is mislabeled: https://github.com/onnx/onnx/issues/2420
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install: # https://github.com/onnx/onnx/issues/2263
	@${FIND} -d ${STAGEDIR}${PREFIX}/include -type d -empty -delete

.include <bsd.port.mk>
