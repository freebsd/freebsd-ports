PORTNAME=	kdialog
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Show nice dialog boxes from shell scripts
WWW=		https://kde.org

USES=		cmake compiler:c++11-lang gettext kde:6 pkgconfig qt:6 tar:xz \
		xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemviews jobwidgets kio notifications parts service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
