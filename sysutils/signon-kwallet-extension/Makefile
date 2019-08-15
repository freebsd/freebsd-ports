# $FreeBSD$

PORTNAME=	signon-kwallet-extension
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KWallet integration for signon framework

LIB_DEPENDS=	libsignon-qt5.so:sysutils/signon-qt5

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm wallet
USE_QT=		core dbus gui \
		buildtools_build qmake_build
USE_LDCONFIG=	${KDE_PREFIX}/${SE_DIR}
PLIST_FILES=	${SE_DIR}/libkeyring-kwallet.so
SE_DIR=		lib/signon/extensions

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
