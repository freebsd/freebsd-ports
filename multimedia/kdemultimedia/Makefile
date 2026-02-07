PORTNAME=	kdemultimedia
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Multimedia applications (meta port)
WWW=		https://apps.kde.org/categories/multimedia/

USES=		kde:6 metaport qt:6

OPTIONS_DEFINE=		DRAGON FFMPEG AUDIOCD_KIO KDENLIVE KMIX
OPTIONS_DEFAULT=	${OPTIONS_DEFINE:NKMIX}

DRAGON_DESC=		Simple video player
DRAGON_RUN_DEPENDS=	dragon-player>=${KDE_APPLICATIONS_VERSION}:multimedia/dragon

FFMPEG_DESC=		FFMPEG-based video thumbnailer
FFMPEG_RUN_DEPENDS=	kdemultimedia-ffmpegthumbs>=${KDE_APPLICATIONS_VERSION}:multimedia/kdemultimedia-ffmpegthumbs

AUDIOCD_KIO_DESC=	Audio CD IOSlave
AUDIOCD_KIO_RUN_DEPENDS=	audiocd-kio>=${KDE_APPLICATIONS_VERSION}:audio/audiocd-kio

# KMix is being replaced by the plasma-pa mixer
KMIX_DESC=		Audio mixer
KMIX_RUN_DEPENDS=	kmix>=${KDE_APPLICATIONS_VERSION}:audio/kmix

KDENLIVE_DESC=		KDE Non-Linear Video Editor
KDENLIVE_RUN_DEPENDS=	kdenlive>=${KDE_APPLICATIONS_VERSION}:multimedia/kdenlive

.include <bsd.port.mk>
