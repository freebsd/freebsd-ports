PORTNAME=	baloo-widgets
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BalooWidgets library
WWW=		https://projects.kde.org/projects/kde/kdelibs/baloo

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	baloo completion config coreaddons emoticons filemetadata \
		i18n init itemmodels jobwidgets kio service solid \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus gui network testlib widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
