#
# Ports collection makefile for:        mythtv-frontend
# Date created:                         14 September 2008
# Whom:                                 Bernhard Fröhlich <decke@bluelife.at>
#
# $FreeBSD$

PORTNAME=	mythtv-frontend
PORTVERSION=	0.23
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/
DISTNAME=	mythtv-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${QT_PREFIX}/lib/qt4/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin

CONFLICTS=	mythtv-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui sql network script linguist_build l10n \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters
REINPLACE_ARGS=	-i ""

DATADIR=	${PREFIX}/share/mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" CPPFLAGS="${CPPFLAGS} ${QTCPPFLAGS}" \
		QTDIR="${QT_PREFIX}" LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-firewire --disable-iptv --disable-hdhomerun \
		--disable-v4l --disable-ivtv --disable-hdpvr --disable-dvb --enable-xvmc \
		--disable-xvmcw --enable-xvmc-pro --enable-opengl-video \
		--disable-directfb --without-bindings=perl,python \
		--enable-glx-procaddrarb

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

DESKTOP_ENTRIES="MythTV Frontend" "MythTV is a homebrew PVR project" "" \
		"mythfrontend" "AudioVideo;Video;" false

OPTIONS=	JACK		"JACK sound driver" off \
		OPENGL		"OpenGL support" on \
		PULSEAUDIO	"PulseAudio audio output support" off \
		VDPAU		"VDPAU support (nvidia only)" off

.include <bsd.port.pre.mk>

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--enable-audio-jack
.else
CONFIGURE_ARGS+=	--disable-audio-jack
.endif

.if defined(WITH_OPENGL)
QT_COMPONENTS+=	opengl
CONFIGURE_ARGS+=	--enable-opengl-video --enable-opengl-vsync
.else
CONFIGURE_ARGS+=	--disable-opengl-video --disable-opengl-vsync
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--enable-audio-pulseoutput
.else
CONFIGURE_ARGS+=	--disable-audio-pulseoutput
.endif

.if defined(WITH_VDPAU)
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/x11/nvidia-driver
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			${WRKSRC}/configure \
			${WRKSRC}/libs/libmythtv/libmythtv.pro \
			${WRKSRC}/libs/libavformat/libavformat.pro \
			${WRKSRC}/bindings/perl/MythTV/Recording.pm \
			${WRKSRC}/programs/mythtranscode/replex/Makefile.standalone \
			${WRKSRC}/programs/scripts/database/mythconverg_backup.pl \
			${WRKSRC}/programs/scripts/database/mythconverg_restore.pl \
			${WRKSRC}/contrib/encoding_converting/mythencode/mythencode.pl \
			${WRKSRC}/contrib/user_jobs/firewire_primer.pl \
			${WRKSRC}/contrib/user_jobs/mythvidexport.py \
			${WRKSRC}/contrib/info/mythname/mythname.pl \
			${WRKSRC}/programs/mythcommflag/mythcommflag-analyze

.include <bsd.port.post.mk>
