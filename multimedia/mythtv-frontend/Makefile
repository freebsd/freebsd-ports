# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	mythtv-frontend
PORTVERSION=	0.26.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.osuosl.org/pub/mythtv/old_releases/ \
		http://ftp.oregonstate.edu/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/old_releases/
DISTNAME=	mythtv-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat \
		yasm:${PORTSDIR}/devel/yasm
LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2

CONFLICTS=	mythtv-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_QT4=	gui sql network script linguist_build l10n sql-mysql_run \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters
REINPLACE_ARGS=	-i ""

DATADIR=	${PREFIX}/share/mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CPPFLAGS+=	${QTCPPFLAGS}
CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${QT_PREFIX}"

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-audio-alsa --disable-indev=alsa \
		--disable-outdev=alsa --disable-firewire --disable-iptv \
		--disable-hdhomerun --disable-v4l2 --disable-ivtv --disable-hdpvr \
		--disable-dvb --enable-opengl-video --without-bindings=perl,python,php

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

DESKTOP_ENTRIES="MythTV Frontend" "MythTV is a homebrew PVR project" "" \
		"mythfrontend" "AudioVideo;Video;" false

OPTIONS_DEFINE=	OPENGL JACK PULSEAUDIO VDPAU
OPTIONS_DEFAULT=	OPENGL

.include <bsd.port.pre.mk>

# for too old binutils in base
.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--enable-audio-jack
.else
CONFIGURE_ARGS+=	--disable-audio-jack
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_QT4+=	opengl
CONFIGURE_ARGS+=	--enable-opengl-video
.else
CONFIGURE_ARGS+=	--disable-opengl-video
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--enable-audio-pulseoutput
.else
CONFIGURE_ARGS+=	--disable-audio-pulseoutput
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
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

.include <bsd.port.post.mk>
