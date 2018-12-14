# $FreeBSD$

PORTNAME=	kdialog
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Show nice dialog boxes from shell scripts

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm guiaddons i18n iconthemes \
		itemviews jobwidgets kdelibs4support kio notifications parts \
		service solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
