PORTNAME=	musikcube
DISTVERSION=	3.0.4
PORTREVISION=	5
CATEGORIES=	multimedia audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal-based music player, audio engine, metadata indexer, server
WWW=		https://musikcube.com/ \
		https://github.com/clangen/musikcube

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	asio130>0:net/asio130 # pending https://github.com/clangen/musikcube/issues/733
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libbasu.so:devel/basu \
		libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libFLAC.so:audio/flac \
		libgme.so:audio/libgme \
		libmicrohttpd.so:www/libmicrohttpd \
		libmp3lame.so:audio/lame \
		libmpg123.so:audio/mpg123 \
		libogg.so:audio/libogg \
		libopenmpt.so:audio/libopenmpt \
		libpipewire-0.3.so:multimedia/pipewire \
		libportaudio.so:audio/portaudio \
		libpulse.so:audio/pulseaudio \
		libsndio.so:audio/sndio \
		libtag.so:audio/taglib \
		libvorbis.so:audio/libvorbis

USES=		cmake compiler:c++17-lang ncurses pkgconfig ssl
USES+=		localbase # workaround for https://github.com/clangen/musikcube/issues/600
USE_LDCONFIG=	yes

CMAKE_ON=	USE_BASU
CMAKE_ARGS+=	-DNCURSES_DISABLE_LIB_SUFFIXES=false

USE_GITHUB=	yes
GH_ACCOUNT=	clangen

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		share/musikcube/libmusikcore.so \
		share/musikcube/musikcube \
		share/musikcube/musikcubed \
		share/musikcube/plugins/*.so

.include <bsd.port.mk>
