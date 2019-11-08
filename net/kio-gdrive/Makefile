# $FreeBSD$

PORTNAME=	kio-gdrive
DISTVERSION=	1.2.7
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE IOSlave for accessing gdrive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libaccounts-qt5.so:net-im/libaccounts-qt5 \
		libkaccounts.so:net-im/kaccounts-integration
RUN_DEPENDS=	kaccounts-providers>=0:net-im/kaccounts-providers

USES=		cmake gettext gnome kde:5 pkgconfig qt:5 tar:xz
USE_GNOME=	intltool
USE_KDE=	completion config coreaddons ecm i18n jobwidgets kio \
		notifications service widgetsaddons \
		gapi
USE_QT=		core dbus gui network widgets xml \
		buildtools_build  qmake_build

.include <bsd.port.mk>
