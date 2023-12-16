PORTNAME=	discover
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 package management tools
WWW=		https://www.kde.org/plasma-desktop

# TODO: update packagekit-qt5
#LIB_DEPENDS=	libpackagekit-qt.so:ports-mgmt/packagekit-qt5
LIB_DEPENDS=	libAppStreamQt5.so:devel/appstream-qt

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext kde:5 \
		pkgconfig qt:5 tar:xz xorg
USE_KDE=	archive attica auth codecs config configwidgets coreaddons \
		crash dbusaddons i18n idletime jobwidgets kcmutils \
		kdeclarative kio kirigami2 newstuff notifications purpose \
		service widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network webview widgets \
		xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

CPE_VENDOR=	kde

.include <bsd.port.mk>
