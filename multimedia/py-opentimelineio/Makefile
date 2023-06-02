PORTNAME=	opentimelineio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	multimedia
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and interchange format for editorial timeline information
WWW=		https://github.com/PixarAnimationStudios/OpenTimelineIO

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cmake:devel/cmake-core
LIB_DEPENDS=	libImath-3_1.so:math/Imath
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}

USES=		compiler:c++14-lang python
USE_PYTHON=	distutils concurrent # autoplist is broken, see https://github.com/PixarAnimationStudios/OpenTimelineIO/issues/1205

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenTimelineIO

GH_TUPLE=	martinmoene:optional-lite:5e4b7760aac85ea73a5b9b91c726fc36cbd4149b:martinmoene_optional_lite/src/deps/optional-lite \
		pybind:pybind11:e7e2c79f3f520f78ffc39fcb34f7919003102733:pybind_pybind11/src/deps/pybind11 \
		Tencent:rapidjson:06d58b9e848c650114556a23294d0b6440078c61:Tencent_rapidjson/src/deps/rapidjson \
		thelink2012:any:bfc77f2e4be6e9a093dd645ef3f1aa30620c9205:thelink2012_any/src/deps/any

PORTSCOUT=	limit:^.*[0-9]$$ # should end with a digit to prevent tags like last_pure_python

.include <bsd.port.mk>
