# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	multimedia kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications (meta-port)

LATEST_LINK=	${PORTNAME}4

NO_BUILD=	yes
USE_KDE4=	kdeprefix

OPTIONS_DEFINE=		DRAGON FFMPEG JUK KIO_AUDIOCD KMIX KSCD MPLAYER
OPTIONS_DEFAULT=	DRAGON FFMPEG JUK KIO_AUDIOCD KMIX KSCD
DRAGON_DESC=		Simple video player
FFMPEG_DESC=		FFMPEG-based video thumbnailer
JUK_DESC=		Audio player
KIO_AUDIOCD_DESC=	Audio CD IOSlave
KMIX_DESC=		Audio mixer
KSCD_DESC=		CD Player
MPLAYER_DESC=		MPlayer-based video thumbnailer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDRAGON}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/dragon:${PORTSDIR}/multimedia/dragon
.endif

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/ffmpegthumbs.so:${PORTSDIR}/multimedia/kdemultimedia4-ffmpegthumbs
.endif

.if ${PORT_OPTIONS:MJUK}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/juk:${PORTSDIR}/audio/juk
.endif

.if ${PORT_OPTIONS:MKIO_AUDIOCD}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/libaudiocdplugins.so.5:${PORTSDIR}/audio/kio-audiocd
.endif

.if ${PORT_OPTIONS:MKMIX}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmix:${PORTSDIR}/audio/kmix
.endif

.if ${PORT_OPTIONS:MKSCD}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kscd:${PORTSDIR}/audio/kscd
.endif

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/mplayerthumbsconfig:${PORTSDIR}/multimedia/kdemultimedia4-mplayerthumbs
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
