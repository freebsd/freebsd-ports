PORTNAME=	musikcube
DISTVERSION=	3.0.1
CATEGORIES=	multimedia audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal-based music player, audio engine, metadata indexer, server
WWW=		https://musikcube.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	asio>0:net/asio
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libbasu.so:devel/basu \
		libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libfaad.so:audio/faad \
		libFLAC.so:audio/flac \
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

USES=		cmake:noninja compiler:c++17-lang pkgconfig ssl
USES+=		localbase # workaround for https://github.com/clangen/musikcube/issues/600
USE_LDCONFIG=	yes
CMAKE_ON=	USE_BASU

USE_GITHUB=	yes
GH_ACCOUNT=	clangen

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		share/musikcube/libmusikcore.so \
		share/musikcube/musikcube \
		share/musikcube/musikcubed \
		share/musikcube/plugins/*.so

.include <bsd.port.options.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1300079
USES+=		ncurses
CMAKE_ARGS+=	-DNCURSES_DISABLE_LIB_SUFFIXES=false
CMAKE_ON+=	FREEBSD_USE_BASE_NCURSES
.else
USES+=		ncurses:port
CFLAGS+=	-I${LOCALBASE}/include/ncurses
CMAKE_ARGS+=	-DNCURSES_DISABLE_LIB_SUFFIXES=true
CMAKE_OFF+=	FREEBSD_USE_BASE_NCURSES
.endif

.include <bsd.port.mk>
