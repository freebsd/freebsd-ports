PORTNAME=	purpose
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	2
CATEGORIES=	misc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Offers available actions for a specific purpose
WWW=		https://api.kde.org/frameworks/purpose/html/index.html

LIB_DEPENDS=	libaccounts-qt5.so:net-im/libaccounts-qt5 \
		libkaccounts.so:net-im/kaccounts-integration
RUN_DEPENDS=	accounts-qml-module>=0:sysutils/accounts-qml-module

USES=		cmake compiler:c++11-lang gettext gnome \
		kde:5 pkgconfig qt:5 tar:xz xorg
USE_GNOME=	intltool
USE_KDE=	config completion coreaddons i18n kdeclarative kio \
		kirigami2 notifications jobwidgets service solid \
		widgetsaddons windowsystem \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

.include <bsd.port.mk>
