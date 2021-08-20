PORTNAME=	kmenuedit
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 menu editor

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons globalaccel guiaddons \
		hotkeys i18n iconthemes init itemmodels itemviews jobwidgets \
		kio notifications parts service solid sonnet \
		textwidgets unitconversion widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		concurrent core dbus gui network printsupport widgets xml\
		buildtools_build qmake_build

.include <bsd.port.mk>
