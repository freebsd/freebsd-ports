PORTNAME=	hana
PORTVERSION=	1.0.0
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/hana/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Create thumbnails from video files
WWW=		https://apps.kde.org/hana/

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	config coreaddons i18n kio kirigami2 \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
