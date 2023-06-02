PORTNAME=	opentimelineio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and interchange format for editorial timeline information
WWW=		https://github.com/PixarAnimationStudios/OpenTimelineIO

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libImath-3_1.so:math/Imath

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenTimelineIO

GH_TUPLE=	martinmoene:optional-lite:5e4b7760aac85ea73a5b9b91c726fc36cbd4149b:martinmoene_optional_lite/src/deps/optional-lite \
		Tencent:rapidjson:06d58b9e848c650114556a23294d0b6440078c61:Tencent_rapidjson/src/deps/rapidjson \
		thelink2012:any:bfc77f2e4be6e9a093dd645ef3f1aa30620c9205:thelink2012_any/src/deps/any

CMAKE_ON=	OTIO_FIND_IMATH

PORTSCOUT=	limit:^.*[0-9]$$ # should end with a digit to prevent tags like last_pure_python

.include <bsd.port.mk>
