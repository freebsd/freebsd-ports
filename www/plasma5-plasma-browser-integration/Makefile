PORTNAME=	plasma-browser-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	www kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 components to integrate browsers into the desktop
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz xorg
USE_KDE=	activities completion config coreaddons crash dbusaddons \
		filemetadata i18n itemmodels jobwidgets kio notifications \
		package plasma-framework plasma-workspace purpose runner \
		service widgetsaddons windowsystem
USE_QT=		concurrent core dbus declarative gui network widgets \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
