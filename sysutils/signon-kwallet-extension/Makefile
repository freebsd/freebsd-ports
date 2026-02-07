PORTNAME=	signon-kwallet-extension
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KWallet integration for signon framework
WWW=		https://projects.kde.org/projects/kde/kdenetwork/signon-kwallet-extension

LIB_DEPENDS=	libsignon-qt6.so:sysutils/signond@qt6

USES=		cmake compiler:c++11-lang kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	wallet \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	${KDE_PREFIX}/${SE_DIR}
PLIST_FILES=	${SE_DIR}/libkeyring-kwallet.so
SE_DIR=		lib/signon/extensions

.include <bsd.port.mk>
