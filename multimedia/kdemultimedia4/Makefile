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

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
		ogg:${PORTSDIR}/audio/libogg \
		tag.1:${PORTSDIR}/audio/taglib \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		musicbrainz3.6:${PORTSDIR}/audio/libmusicbrainz3 \
		swscale.1:${PORTSDIR}/multimedia/ffmpeg

.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
KDE4_BUILDENV=	yes
USE_QT4=	dbus qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes
CMAKE_ARGS=	-DWITH_TunePimp:BOOL=OFF

OPTIONS=	ALSA "Build with ALSA compatibility library" off \
		PULSEAUDIO "KMix control for PulseAudio" off

.include <bsd.port.options.mk>

.if !defined(WITH_ALSA)
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-no_alsa
.else
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.endif

.if defined(WITH_PULSEAUDIO)
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
USE_GNOME=	glib20
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
