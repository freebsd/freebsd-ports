# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	multimedia kde
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications (meta port)

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes
USE_KDE4=	kdeprefix

OPTIONS_DEFINE=		DRAGON FFMPEG JUK KIO_AUDIOCD KMIX KSCD MPLAYER
OPTIONS_DEFAULT=	DRAGON FFMPEG JUK KIO_AUDIOCD KMIX KSCD

DRAGON_DESC=		Simple video player
DRAGON_RUN_DEPENDS=	${KDE4_PREFIX}/bin/dragon:${PORTSDIR}/multimedia/dragon

FFMPEG_DESC=		FFMPEG-based video thumbnailer
FFMPEG_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/ffmpegthumbs.so:${PORTSDIR}/multimedia/kdemultimedia4-ffmpegthumbs

JUK_DESC=		Audio player
JUK_RUN_DEPENDS=	${KDE4_PREFIX}/bin/juk:${PORTSDIR}/audio/juk

KIO_AUDIOCD_DESC=	Audio CD IOSlave
KIO_AUDIOCD_RUN_DEPENDS=	${KDE4_PREFIX}/lib/libaudiocdplugins.so:${PORTSDIR}/audio/kio-audiocd

KMIX_DESC=		Audio mixer
KMIX_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kmix:${PORTSDIR}/audio/kmix

KSCD_DESC=		CD Player
KSCD_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kscd:${PORTSDIR}/audio/kscd

MPLAYER_DESC=		MPlayer-based video thumbnailer
MPLAYER_RUN_DEPENDS=	${KDE4_PREFIX}/bin/mplayerthumbsconfig:${PORTSDIR}/multimedia/kdemultimedia4-mplayerthumbs

.include <bsd.port.mk>
