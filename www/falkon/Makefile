# $FreeBSD$

PORTNAME=	falkon
DISTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	KDE/stable/falkon/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser based on WebKit engine and Qt Framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake desktop-file-utils kde:5 qt:5 ssl tar:xz
USE_KDE=	ecm_build i18n
USE_QT=		core dbus declarative gui location network printsupport \
		sql webchannel webengine widgets x11extras \
		buildtools_build qmake_build linguist_build
USE_XORG=	xcb

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOMEKEYRING KWALLET
OPTIONS_DEFAULT=	KWALLET
OPTIONS_SUB=	YES

KWALLET_USE=	KDE=wallet
KWALLET_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_KF5Wallet=ON

GNOMEKEYRING_CMAKE_BOOL=	BUILD_KEYRING
GNOMEKEYRING_USE=		GNOME=glib20
GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring

.include <bsd.port.mk>
