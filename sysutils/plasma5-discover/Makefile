PORTNAME=	discover
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 package management tools

# TODO: update packagekit-qt5
#LIB_DEPENDS=	libpackagekit-qt.so:ports-mgmt/packagekit-qt5

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext kde:5 \
		pkgconfig qt:5 tar:xz
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons crash dbusaddons i18n iconthemes idletime \
		itemmodels itemviews jobwidgets kcmutils kdeclarative kio \
		kirigami2 newstuff notifications package plasma-framework \
		service solid textwidgets wallet widgetsaddons windowsystem \
		xmlgui \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network svg widgets \
		x11extras xml \
		buildtools_build qmake_build testlib_build

CPE_VENDOR=	kde

.include <bsd.port.mk>
