PORTNAME=	inputstream.adaptive
DISTVERSION=	21.5.15
DISTVERSIONSUFFIX=	-Omega
CATEGORIES=	multimedia
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Adaptive stream support for Kodi
WWW=		https://github.com/peak3d/inputstream.adaptive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	googletest>0:devel/googletest \
		rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++14-lang kodi
USE_GITHUB=	yes
GH_ACCOUNT=	peak3d xbmc:bento4
GH_PROJECT=	Bento4:bento4
GH_TAGNAME=	1.6.0-641-3-Omega:bento4

CMAKE_ARGS+=	-DENABLE_INTERNAL_BENTO4:BOOL=ON -DBENTO4_URL=${DISTDIR}/${DISTFILE_bento4}

.include <bsd.port.mk>
