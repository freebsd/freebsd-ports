# $FreeBSD$

PORTNAME=	libksysguard
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to track and control running processes

USES=		cmake compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		globalaccel i18n iconthemes jobwidgets kio newstuff package \
		plasma-framework service widgetsaddons windowsystem
USE_QT=		concurrent core dbus gui network script webkit widgets x11extras xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	WEBENGINE

WEBENGINE_USE=	QT=webengine
WEBENGINE_DESC=	HTML-based GUI ksysguard library based on Qt5WebEngine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
