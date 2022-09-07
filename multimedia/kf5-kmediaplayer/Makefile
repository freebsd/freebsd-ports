PORTNAME=	kmediaplayer
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 plugin interface for media player features
WWW=		https://api.kde.org/frameworks/kmediaplayer/html/index.html

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n jobwidgets kio parts service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build testlib_build
USE_XORG=	x11

.include <bsd.port.mk>
