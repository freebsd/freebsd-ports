PORTNAME=	musikcube
DISTVERSION=	0.96.11
CATEGORIES=	multimedia audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal-based music player, audio engine, metadata indexer, server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
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
		libsndio.so:audio/sndio \
		libtag.so:audio/taglib \
		libvorbis.so:audio/libvorbis

USES=		cmake:noninja compiler:c++14-lang pkgconfig ssl
USE_LDCONFIG=	yes

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
CMAKE_ARGS=	-DNCURSES_DISABLE_LIB_SUFFIXES=false
CMAKE_ON=	FREEBSD_USE_BASE_NCURSES
.else
USES+=		ncurses:port
CFLAGS+=	-I${LOCALBASE}/include/ncurses
CMAKE_ARGS=	-DNCURSES_DISABLE_LIB_SUFFIXES=true
CMAKE_OFF=	FREEBSD_USE_BASE_NCURSES
.endif

.include <bsd.port.mk>
