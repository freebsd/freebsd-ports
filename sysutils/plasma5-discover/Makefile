# $FreeBSD$

PORTNAME=	discover
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 package management tools

# TODO: update packagekit-qt5
#LIB_DEPENDS=	libpackagekit-qt.so:ports-mgmt/packagekit-qt5

USES=		cmake:outsource compiler:c++11-lib cpe desktop-file-utils \
		gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm i18n iconthemes itemmodels \
		itemviews jobwidgets kdeclarative kio kirigami2 newstuff \
		notifications package plasma-framework service solid \
		textwidgets wallet widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui network svg testlib widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
