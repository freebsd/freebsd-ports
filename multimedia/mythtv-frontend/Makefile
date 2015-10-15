# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythtv-frontend
PORTVERSION=	0.27.0.20140121
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freebsd.org/~decke/distfiles/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat \
		yasm:${PORTSDIR}/devel/yasm
LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libtag.so:${PORTSDIR}/audio/taglib \
		libxml2.so:${PORTSDIR}/textproc/libxml2

CONFLICTS=	mythtv-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythtv
GH_TAGNAME=	5a5e1cd

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
		QTDIR="${QT_PREFIX}"
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}" --cxx="${CXX}" --libxml2-path="${LOCALBASE}/include/libxml2" \
		--disable-audio-alsa --disable-indev=alsa --disable-outdev=alsa --disable-firewire \
		--disable-hdhomerun --disable-v4l2 --disable-ivtv --disable-hdpvr \
		--disable-dvb --enable-opengl-video --without-bindings=perl,python,php

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

DESKTOP_ENTRIES="MythTV Frontend" "MythTV is a homebrew PVR project" "" \
		"mythfrontend" "AudioVideo;Video;" false

OPTIONS_DEFINE=	OPENGL JACK PULSEAUDIO VDPAU
OPTIONS_DEFAULT=	OPENGL

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ENABLE=	audio-jack

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	audio-pulseoutput

VDPAU_LIB_DEPENDS=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

OPENGL_CONFIGURE_ENABLE=	opengl-video

.if ${PORT_OPTIONS:MOPENGL}
USE_QT4+=	opengl
.endif

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
