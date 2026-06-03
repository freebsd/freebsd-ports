PORTNAME=	opentimelineio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	API and interchange format for editorial timeline information
WWW=		https://github.com/PixarAnimationStudios/OpenTimelineIO

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson
LIB_DEPENDS=	libImath.so:math/Imath

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenTimelineIO

CMAKE_ON=	OTIO_FIND_IMATH OTIO_FIND_RAPIDJSON
CMAKE_OFF=	OTIO_DEPENDENCIES_INSTALL

PORTSCOUT=	limit:^.*[0-9]$$ # should end with a digit to prevent tags like last_pure_python

.include <bsd.port.mk>
