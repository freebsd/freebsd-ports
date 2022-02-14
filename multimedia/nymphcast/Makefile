PORTNAME=	NymphCast
DISTVERSION=	v0.1-rc0
CATEGORIES=	multimedia

# -p3 because WRKSRC_SUBDIR is set; the patches are from the toplevel,
# similarly the LICENSE_FILE lives at the toplevel of the upstream
# source repo, outside of WRKSRC_SUBDIR.
PATCHFILES=	e4de6983e738acff88db8c81a2e5bb0760db5855.patch:-p3 \
		1d32a9d470dd8b6c2af5f6638b53b9a012865cc7.patch:-p3 \
		40e8c286f7d5f37e976e655a086d5630107c7f09.patch:-p3 \
		9e192666796bdb1913a2f965314a8cf51c2a644f.patch:-p3
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Audio and video source for a television or powered speakers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	rapidjson>=0:devel/rapidjson
LIB_DEPENDS=	libnymphrpc.so:multimedia/nymphrpc \
		libnymphcast.so:multimedia/nymphcastlib \
		libasound.so:audio/alsa-lib \
		libPocoFoundation.so:devel/poco \
		libSDL2.so:devel/sdl20 \
		libcurl.so:ftp/curl \
		libfreeimage.so:graphics/freeimage \
		libSDL2_image-2.0.so.0:graphics/sdl2_image \
		libavutil.so:multimedia/ffmpeg \
		libvlccore.so:multimedia/vlc \
		libfreetype.so:print/freetype2

USES=		compiler:c++17-lang gl gmake pkgconfig
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	MayaPosch

WRKSRC_SUBDIR=	src/server

post-extract:
	${MV} ${WRKSRC}/version ${WRKSRC}/version.mk

.include <bsd.port.mk>
