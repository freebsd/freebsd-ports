PORTNAME=	opentimelineio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and interchange format for editorial timeline information
WWW=		https://github.com/AcademySoftwareFoundation/OpenTimelineIO

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libImath.so:math/Imath
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++14-lang python:3.11+
USE_PYTHON=	distutils concurrent # autoplist is broken, see https://github.com/PixarAnimationStudios/OpenTimelineIO/issues/1205

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	OpenTimelineIO

GH_TUPLE=	pybind:pybind11:a2e59f0e7065404b44dfe92a28aca47ba1378dc4:pybind_pybind11/src/deps/pybind11 \
		Tencent:rapidjson:24b5e7a8b27f42fa16b96fc70aade9106cf7102f:Tencent_rapidjson/src/deps/rapidjson

PORTSCOUT=	limit:^.*[0-9]$$ # should end with a digit to prevent tags like last_pure_python

.include <bsd.port.mk>
