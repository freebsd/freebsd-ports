#
# Ports collection makefile for:        mythtv-frontend
# Date created:                         14 September 2008
# Whom:                                 Bernhard Fröhlich <decke@bluelife.at>
#
# $FreeBSD$

PORTNAME=	mythtv-frontend
PORTVERSION=	0.22
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/
DISTNAME=	mythtv-${PORTVERSION}

MAINTAINER=	decke@bluelife.at
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
USE_LDCONFIG=	yes
REINPLACE_ARGS=	-i ""

DATADIR=	${PREFIX}/share/mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" CPPFLAGS="${CPPFLAGS}  ${QTCPPFLAGS}" \
		QTDIR="${QT_PREFIX}" KDEDIR="${KDE_PREFIX}" LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-v4l --disable-ivtv --disable-firewire \
		--disable-dvb --disable-dbox2 --disable-hdhomerun --disable-iptv \
		--disable-hdpvr --without-bindings=perl,python \
		--enable-xvmc --enable-xvmc-pro --disable-xvmcw --enable-glx-procaddrarb

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

DESKTOP_ENTRIES="MythTV Frontend" "MythTV is a homebrew PVR project" "" \
		"mythfrontend" "AudioVideo;Video;" false

OPTIONS=	ARTS "arts sound driver" off \
		JACK "JACK sound driver" off \
		OPENGL "OpenGL support" on

.include <bsd.port.pre.mk>

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-audio-arts
.else
CONFIGURE_ARGS+=	--disable-audio-arts
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--enable-audio-jack
.else
CONFIGURE_ARGS+=	--disable-audio-jack
.endif

.if defined(WITH_OPENGL)
CONFIGURE_ARGS+=	--enable-opengl-video
.else
CONFIGURE_ARGS+=	--disable-opengl-video
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			${WRKSRC}/libs/libmythtv/libmythtv.pro \
			${WRKSRC}/libs/libavformat/libavformat.pro \
			${WRKSRC}/bindings/perl/MythTV/Recording.pm \
			${WRKSRC}/programs/mythtranscode/replex/Makefile.standalone \
			${WRKSRC}/programs/scripts/database/mythconverg_backup.pl

.include <bsd.port.post.mk>
