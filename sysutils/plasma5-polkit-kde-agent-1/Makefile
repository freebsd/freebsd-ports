# $FreeBSD$

PORTNAME=	polkit-kde-agent-1
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 daemon providing a polkit authentication UI

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt@qt5

USES=		cmake compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons crash dbusaddons ecm i18n iconthemes \
		notifications widgetsaddons windowsystem
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
