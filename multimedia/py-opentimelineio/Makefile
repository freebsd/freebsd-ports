PORTNAME=	opentimelineio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and interchange format for editorial timeline information
WWW=		https://github.com/PixarAnimationStudios/OpenTimelineIO

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libImath.so:math/Imath
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++14-lang python:3.11+
USE_PYTHON=	distutils concurrent # autoplist is broken, see https://github.com/PixarAnimationStudios/OpenTimelineIO/issues/1205

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenTimelineIO

GH_TUPLE=	pybind:pybind11:v2.13.5:pybind_pybind11/src/deps/pybind11 \
		Tencent:rapidjson:06d58b9e848c650114556a23294d0b6440078c61:Tencent_rapidjson/src/deps/rapidjson

PORTSCOUT=	limit:^.*[0-9]$$ # should end with a digit to prevent tags like last_pure_python

.include <bsd.port.mk>
