# $FreeBSD$

PORTNAME=	kdewebkit
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing integration of QtWebKit

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		ecm i18n jobwidgets kio parts service sonnet textwidgets \
		wallet widgetsaddons xmlgui
USE_QT=		buildtools_build core dbus gui network qmake_build webkit \
		widgets xml

.include <bsd.port.mk>
