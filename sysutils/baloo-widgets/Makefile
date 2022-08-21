PORTNAME=	baloo-widgets
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-applications

PATCH_SITES=	https://invent.kde.org/libraries/baloo-widgets/commit/
PATCHFILES=	7ff54ae9b68ca0edf3d6cd57c3eefb6cf072b6f8.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BalooWidgets library

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	baloo completion config coreaddons emoticons filemetadata \
		i18n init itemmodels jobwidgets kio service solid \
		widgetsaddons windowsystem \
		ecm_build
USE_QT=		concurrent core dbus gui network testlib widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
