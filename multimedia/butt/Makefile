PORTNAME=	butt
PORTVERSION=	1.44.0
PORTREVISION=	1
CATEGORIES=	multimedia graphics
MASTER_SITES=	https://danielnoethen.de/butt/release/${PORTVERSION}/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Broadcast SHOUTcast and Icecast streams
WWW=		https://danielnoethen.de/butt/

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libFLAC.so:audio/flac \
		libfdk-aac.so:audio/fdk-aac \
		libfltk_images.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libpng.so:graphics/png \
		libportaudio.so:audio/portaudio \
		libportmidi.so:audio/portmidi \
		libsamplerate.so:audio/libsamplerate \
		libvorbis.so:audio/libvorbis

USES=		autoreconf compiler:c++11-lang gettext \
		gmake jpeg pkgconfig xorg ssl uidfix
USE_XORG=	x11 xrender xcursor xfixes xext xft xinerama
GNU_CONFIGURE=	yes
CFLAGS+=	-I/usr/local/include
LDFLAGS+=	-L/usr/local/lib -lintl
PLIST_FILES=	bin/butt \
		share/locale/ar/LC_MESSAGES/butt.mo \
		share/locale/de/LC_MESSAGES/butt.mo \
		share/locale/es/LC_MESSAGES/butt.mo \
		share/locale/fr/LC_MESSAGES/butt.mo \
		share/locale/nl/LC_MESSAGES/butt.mo \
		share/locale/pt_BR/LC_MESSAGES/butt.mo

.include <bsd.port.mk>
