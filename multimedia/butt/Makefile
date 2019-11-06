# $FreeBSD$

PORTNAME=	butt
PORTVERSION=	0.1.18
PORTREVISION=	1
CATEGORIES=	multimedia graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Broadcast SHOUTcast and Icecast streams

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libFLAC.so:audio/flac \
		libfdk-aac.so:audio/fdk-aac \
		libfltk_images.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libpng.so:graphics/png \
		libportaudio.so:audio/portaudio \
		libsamplerate.so:audio/libsamplerate \
		libvorbis.so:audio/libvorbis

USES=		autoreconf compiler:c++11-lang gmake jpeg pkgconfig xorg
USE_XORG=	x11 xrender xcursor xfixes xext xft xinerama

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/butt

.include <bsd.port.mk>
