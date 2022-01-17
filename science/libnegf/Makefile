PORTNAME=	libnegf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Non Equilibrium Green's Functions library

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake:testing fortran python:build
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

.include <bsd.port.mk>
