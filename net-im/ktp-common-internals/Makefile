# $FreeBSD$

PORTNAME=	ktp-common-internals
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Telepathy internal library

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libsignon-qt5.so:sysutils/signon-qt5 \
		libtelepathy-qt5.so:net-im/telepathy-qt5 \
		libtelepathy-logger-qt.so:net-im/telepathy-logger-qt5 \
		libotr.so:security/libotr \
		libaccounts-qt5.so:net-im/libaccounts-qt5 \
		libkaccounts.so:net-im/kaccounts-integration
RUN_DEPENDS=	${LOCALBASE}/lib/mission-control-plugins.0/mcp-account-manager-accounts-sso.so:net-im/telepathy-accounts-signon \
		${LOCALBASE}/libexec/mission-control-5:net-im/telepathy-mission-control

USES=		cmake:outsource gettext pkgconfig kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes itemviews jobwidgets kcmutils \
		kio notifications notifyconfig parts people service solid \
		sonnet texteditor textwidgets wallet widgetsaddons windowsystem \
		xmlgui
USE_QT=		core dbus gui network qml sql widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
