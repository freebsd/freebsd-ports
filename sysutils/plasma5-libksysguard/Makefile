PORTNAME=	libksysguard
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to track and control running processes
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		globalaccel i18n iconthemes jobwidgets kdeclarative kio \
		newstuff package plasma-framework service solid \
		widgetsaddons windowsystem
USE_QT=		concurrent core dbus declarative gui network script webkit \
		widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	WEBENGINE

WEBENGINE_USE=	QT=webengine
WEBENGINE_DESC=	HTML-based GUI ksysguard library based on Qt5WebEngine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
