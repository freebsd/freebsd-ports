PORTNAME=	kio-gdrive
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE IOSlave for accessing gdrive
WWW=		https://www.kde.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6 \
		libaccounts-qt6.so:net-im/libaccounts-qt@qt6 \
		libkaccounts6.so:net-im/kaccounts-integration
RUN_DEPENDS=	kaccounts-providers>=0:net-im/kaccounts-providers

USES=		cmake gettext gnome kde:6 pkgconfig qt:6 tar:xz
USE_GNOME=	intltool
USE_KDE=	completion config coreaddons gapi i18n jobwidgets kio \
		notifications purpose service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
