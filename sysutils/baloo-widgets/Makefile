PORTNAME=	baloo-widgets
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BalooWidgets library
WWW=		https://projects.kde.org/projects/kde/kdelibs/baloo

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	baloo completion config coreaddons filemetadata i18n \
		itemmodels jobwidgets kio service solid widgetsaddons \
		windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
