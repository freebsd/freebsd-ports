# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications (meta port)

USES=		kde:4 metaport

OPTIONS_DEFINE=		DRAGON FFMPEG JUK KIO_AUDIOCD KMIX KSCD MPLAYER
OPTIONS_DEFAULT=	DRAGON FFMPEG JUK KIO_AUDIOCD KMIX KSCD

DRAGON_DESC=		Simple video player
DRAGON_RUN_DEPENDS=	${KDE_PREFIX}/bin/dragon:multimedia/dragon

FFMPEG_DESC=		FFMPEG-based video thumbnailer
FFMPEG_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/ffmpegthumbs.so:multimedia/kdemultimedia4-ffmpegthumbs

JUK_DESC=		Audio player
JUK_RUN_DEPENDS=	${KDE_PREFIX}/bin/juk:audio/juk

KIO_AUDIOCD_DESC=	Audio CD IOSlave
KIO_AUDIOCD_RUN_DEPENDS=	${KDE_PREFIX}/lib/libaudiocdplugins.so:audio/kio-audiocd

KMIX_DESC=		Audio mixer
KMIX_RUN_DEPENDS=	${KDE_PREFIX}/bin/kmix:audio/kmix

KSCD_DESC=		CD Player
KSCD_RUN_DEPENDS=	${KDE_PREFIX}/bin/kscd:audio/kscd

MPLAYER_DESC=		MPlayer-based video thumbnailer
MPLAYER_RUN_DEPENDS=	${KDE_PREFIX}/bin/mplayerthumbsconfig:multimedia/kdemultimedia4-mplayerthumbs

.include <bsd.port.mk>
