# $FreeBSD$

PORTNAME=	kmenuedit
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 menu editor

USES=		cmake:outsource compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons ecm emoticons hotkeys \
		i18n iconthemes init itemmodels itemviews jobwidgets \
		kdelibs4support kio notifications parts service solid sonnet \
		textwidgets unitconversion widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets xml\
		buildtools_build qmake_build

.include <bsd.port.mk>
