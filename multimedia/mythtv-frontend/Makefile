# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythtv-frontend
PORTVERSION=	0.27.5.20150616
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		yasm:devel/yasm
LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libfreetype.so:print/freetype2 \
		libtag.so:audio/taglib \
		libxml2.so:textproc/libxml2

CONFLICTS=	mythtv-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythtv
GH_TAGNAME=	ad97d24

WRKSRC_SUBDIR=	${GH_PROJECT}

ONLY_FOR_ARCHS=	i386 amd64
NOPRECIOUSMAKEVARS=	# don't override $(ARCH) in ffmpeg makefiles
USES=		gmake libtool pkgconfig
USE_QT4=	gui sql network script linguist_build l10n sql-mysql_run \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters
REINPLACE_ARGS=	-i ""
DESTDIRNAME=	INSTALL_ROOT

DATADIR=	${PREFIX}/share/mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CPPFLAGS+=	${QTCPPFLAGS}
CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${QT_PREFIX}" \
		PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}" --cxx="${CXX}" --libxml2-path="${LOCALBASE}/include/libxml2" \
		--disable-audio-alsa --disable-indev=alsa --disable-outdev=alsa --disable-mythlogserver \
		--disable-firewire --disable-hdhomerun --disable-v4l2 --disable-ivtv --disable-hdpvr \
		--disable-dvb --enable-opengl-video --without-bindings=perl,python,php

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

DESKTOP_ENTRIES="MythTV Frontend" "MythTV is a homebrew PVR project" "" \
		"mythfrontend" "AudioVideo;Video;" false

OPTIONS_DEFINE=	OPENGL JACK PULSEAUDIO VDPAU
OPTIONS_DEFAULT=	OPENGL

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	audio-jack

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	audio-pulseoutput

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

OPENGL_CONFIGURE_ENABLE=	opengl-video
OPENGL_USE=	QT4=opengl

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			${WRKSRC}/configure \
			${WRKSRC}/libs/libmythtv/libmythtv.pro \
			${WRKSRC}/bindings/perl/MythTV/Recording.pm \
			${WRKSRC}/programs/mythtranscode/replex/Makefile.standalone \
			${WRKSRC}/programs/scripts/database/mythconverg_backup.pl \
			${WRKSRC}/programs/scripts/database/mythconverg_restore.pl \
			${WRKSRC}/programs/mythcommflag/mythcommflag-analyze

.include <bsd.port.mk>
