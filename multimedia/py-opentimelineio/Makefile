PORTNAME=	opentimelineio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and interchange format for editorial timeline information

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cmake:devel/cmake

USES=		compiler:c++14-lang python
USE_PYTHON=	distutils concurrent # autoplist is broken, see https://github.com/PixarAnimationStudios/OpenTimelineIO/issues/1205

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenTimelineIO

GH_TUPLE=	google:googletest:ba96d0b1161f540656efdaed035b3c062b60e006:google_googletest/src/deps/rapidjson/thirdparty/gtest \
		martinmoene:optional-lite:a006f229a77b3b2dacf927e4029b8c1c60c86b52:martinmoene_optional_lite/src/deps/optional-lite \
		pybind:pybind11:e7e2c79f3f520f78ffc39fcb34f7919003102733:pybind_pybind11/src/deps/pybind11 \
		Tencent:rapidjson:4d6cb08189cf7336821f04090b612baa2ca6a90d:Tencent_rapidjson/src/deps/rapidjson \
		thelink2012:any:f67bd5f8bbf7eb628bf38206d4ac5cb22438e6bb:thelink2012_any/src/deps/any

.include <bsd.port.mk>
