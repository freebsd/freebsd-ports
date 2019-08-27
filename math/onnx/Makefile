# $FreeBSD$

PORTNAME=	onnx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Neural Network eXchange

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++11-lang python:build
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install: # https://github.com/onnx/onnx/issues/2263
	@${FIND} -d ${STAGEDIR}${PREFIX}/include -type d -empty -delete

.include <bsd.port.mk>
