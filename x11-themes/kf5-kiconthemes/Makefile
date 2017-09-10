# Created by: tcberner
# $FreeBSD$

PORTNAME=	kiconthemes
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for handling icons in applications

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	archive auth codecs config configwidgets coreaddons ecm \
		i18n itemviews widgetsaddons
USE_QT5=	buildtools_build concurrent core dbus gui qmake_build \
		script svg widgets xml

.include <bsd.port.mk>
