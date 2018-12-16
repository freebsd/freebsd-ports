# $FreeBSD$

PORTNAME=	kiconthemes
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for handling icons in applications

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs config configwidgets coreaddons ecm \
		i18n itemviews widgetsaddons
USE_QT=		buildtools_build concurrent core dbus gui qmake_build \
		script svg widgets xml

OPTIONS_DEFINE=	ICONS
OPTIONS_DEFAULT=	ICONS
ICONS_DESC=	Install Breeze Icons
ICONS_USE=	KDE=breeze-icons_run

.include <bsd.port.mk>
