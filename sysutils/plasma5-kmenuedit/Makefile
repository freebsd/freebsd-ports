PORTNAME=	kmenuedit
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 menu editor
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons globalaccel guiaddons \
		hotkeys i18n iconthemes init itemmodels itemviews jobwidgets \
		kio notifications parts service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
