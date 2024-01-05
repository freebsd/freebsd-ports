PORTNAME=	kio-gdrive
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE IOSlave for accessing gdrive
WWW=		https://www.kde.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libaccounts-qt5.so:net-im/libaccounts-qt@qt5 \
		libkaccounts.so:net-im/kaccounts-integration
RUN_DEPENDS=	kaccounts-providers>=0:net-im/kaccounts-providers

USES=		cmake gettext gnome kde:5 pkgconfig qt:5 tar:xz
USE_GNOME=	intltool
USE_KDE=	completion config coreaddons i18n jobwidgets kio \
		notifications purpose service solid widgetsaddons windowsystem \
		gapi \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build  qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
