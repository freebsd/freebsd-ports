# $FreeBSD$

PORTNAME=	kdemultimedia
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications (meta port)

USES=		kde:5 metaport qt:5
USE_QT=		#

OPTIONS_DEFINE=		DRAGON FFMPEG AUDIOCD_KIO KMIX
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

DRAGON_DESC=		Simple video player
DRAGON_RUN_DEPENDS=	dragon-player>=${KDE_APPLICATIONS_VERSION}:multimedia/dragon

FFMPEG_DESC=		FFMPEG-based video thumbnailer
FFMPEG_RUN_DEPENDS=	kdemultimedia-ffmpegthumbs>=${KDE_APPLICATIONS_VERSION}:multimedia/kdemultimedia-ffmpegthumbs

AUDIOCD_KIO_DESC=	Audio CD IOSlave
AUDIOCD_KIO_RUN_DEPENDS=	audiocd-kio>=${KDE_APPLICATIONS_VERSION}:audio/audiocd-kio

KMIX_DESC=		Audio mixer
KMIX_RUN_DEPENDS=	kmix>=${KDE_APPLICATIONS_VERSION}:audio/kmix

.include <bsd.port.mk>
