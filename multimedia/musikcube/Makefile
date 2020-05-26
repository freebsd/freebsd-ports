# $FreeBSD$

PORTNAME=	musikcube
DISTVERSION=	0.92.1
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
		libogg.so:audio/libogg \
		libsndio.so:audio/sndio \
		libtag.so:audio/taglib \
		libvorbis.so:audio/libvorbis

USES=		cmake:noninja compiler:c++14-lang ncurses:port pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	clangen
USE_LDCONFIG=	yes

.include <bsd.port.mk>
