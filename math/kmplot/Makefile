PORTNAME=	kmplot
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mathematical function plotter for KDE
WWW=		https://www.kde.org/applications/education/kmplot

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kio notifications parts \
		service solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
