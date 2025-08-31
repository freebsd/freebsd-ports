PORTNAME=	NymphCast
DISTVERSION=	v0.1
PORTREVISION=	7
CATEGORIES=	multimedia

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Audio and video source for a television or powered speakers
WWW=		http://nyanko.ws/nymphcast.php

# The LICENSE_FILE lives outside the top-of-the-tree because
# WRKSRC_SUBDIR is set.
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	rapidjson>=0:devel/rapidjson
LIB_DEPENDS=	libnymphrpc.so:multimedia/nymphrpc \
		libnymphcast.so:multimedia/nymphcastlib \
		libasound.so:audio/alsa-lib \
		libPocoFoundation.so:devel/poco \
		libcurl.so:ftp/curl \
		libfreeimage.so:graphics/freeimage \
		libavutil.so:multimedia/ffmpeg \
		libvlccore.so:multimedia/vlc \
		libfreetype.so:print/freetype2

USES=		compiler:c++17-lang gl gmake pkgconfig sdl
USE_GL=		gl
USE_SDL=	sdl2 image2

USE_GITHUB=	yes
GH_ACCOUNT=	MayaPosch

WRKSRC_SUBDIR=	src/server

.include <bsd.port.mk>
