PORTNAME=	kdewebkit
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing integration of QtWebKit

DEPRECATED=	Depends on deprecated www/qt5-webkit
EXPIRATION_DATE=	2023-12-31

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n jobwidgets kio parts service sonnet solid \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network webkit widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
