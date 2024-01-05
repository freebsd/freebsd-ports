PORTNAME=	mpvqt
DISTVERSION=	1.0.0
MASTER_SITES=	KDE/stable/${PORTNAME}/
CATEGORIES=	multimedia kde

COMMENT=	MpvQt is a libmpv wrapper for QtQuick2 and QML
WWW=		https://invent.kde.org/libraries/mpvqt
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
