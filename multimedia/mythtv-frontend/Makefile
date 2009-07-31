#
# Ports collection makefile for:        mythtv-frontend
# Date created:                         14 September 2008
# Whom:                                 Bernhard Fröhlich <decke@bluelife.at>
#
# $FreeBSD$

PORTNAME=	mythtv-frontend
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/
DISTNAME=	mythtv-${PORTVERSION}

MAINTAINER=	decke@bluelife.at
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin

CONFLICTS=	mythtv-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" CPPFLAGS="${CPPFLAGS}  ${QTCPPFLAGS}" \
		QTDIR="${QT_PREFIX}" KDEDIR="${KDE_PREFIX}" \
		CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--prefix="${PREFIX}" --disable-v4l --disable-ivtv --disable-firewire \
		--disable-dvb --disable-dbox2 --disable-hdhomerun --disable-iptv \
		--without-bindings=perl,python --enable-xvmc --enable-xvmc-pro --disable-xvmcw \
		--enable-glx-procaddrarb

QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

OPTIONS=	ARTS "arts sound driver" off \
		JACK "JACK sound driver" off \
		OPENGL "OpenGL video support (see pre-build message)" off

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Please hit Ctrl-C right now and install QT 3.3 with"
	@${ECHO_MSG} "OpenGL support with the following command, if it isn't"
	@${ECHO_MSG} "already:"
	@${ECHO_MSG}
	@${ECHO_MSG} "    cd /usr/ports/x11-toolkits/qt33"
	@${ECHO_MSG} "    make WITH_OPENGL=yes install clean"
	@${ECHO_MSG}
	@sleep 3

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

.include <bsd.port.post.mk>
