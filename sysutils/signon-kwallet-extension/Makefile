PORTNAME=	signon-kwallet-extension
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KWallet integration for signon framework
WWW=		https://projects.kde.org/projects/kde/kdenetwork/signon-kwallet-extension

LIB_DEPENDS=	libsignon-qt5.so:sysutils/signond@qt5

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	wallet \
		ecm:build
USE_QT=		core dbus gui \
		buildtools:build qmake:build
USE_LDCONFIG=	${KDE_PREFIX}/${SE_DIR}
PLIST_FILES=	${SE_DIR}/libkeyring-kwallet.so
SE_DIR=		lib/signon/extensions

.include <bsd.port.mk>
