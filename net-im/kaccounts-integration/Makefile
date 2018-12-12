# $FreeBSD$

PORTNAME=	kaccounts-integration
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System to administer web accounts for the KDE desktop

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libaccounts-qt5.so:net-im/libaccounts-qt5 \
		liboauth2plugin.so:sysutils/signon-plugin-oauth2 \
		libsignon-qt5.so:sysutils/signon-qt5 \
		libkeyring-kwallet.so:sysutils/signon-kwallet-extension
RUN_DEPENDS=	signon-ui:sysutils/signon-ui

USES=		cmake:outsource compiler:c++11-lang gettext pkgconfig kde:5 \
		qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons ecm \
		i18n iconthemes kcmutils kio service wallet widgetsaddons \
		akonadi
USE_QT=		dbus core declarative gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
