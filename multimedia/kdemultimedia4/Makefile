# New ports collection Makefile for:	kdemultimedia
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
		ogg.7:${PORTSDIR}/audio/libogg \
		tag.1:${PORTSDIR}/audio/taglib \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp \
		xine.1:${PORTSDIR}/multimedia/libxine \
		swscale.1:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

CONFLICTS=	dolphin-plugins-mplayerthumbs-1.*
LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support designer network svg qtestlib \
		qmake_build moc_build rcc_build uic_build
USE_OPENLDAP=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	PULSEAUDIO "KMix control for PulseAudio" off \
		ALSA "Build with ALSA compatibility library" off

.include <bsd.port.options.mk>

.if !defined(WITH_ALSA)
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-CMakeLists.txt
.else
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.endif

.if defined(WITH_PULSEAUDIO)
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

.include <bsd.port.mk>
