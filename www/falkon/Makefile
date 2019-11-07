# $FreeBSD$

PORTNAME=	falkon
DISTVERSION=	3.1.0
CATEGORIES=	www
MASTER_SITES=	KDE/stable/falkon/${DISTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser based on Webengine and Qt Framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake desktop-file-utils kde:5 qt:5 ssl tar:xz xorg
USE_KDE=	ecm_build i18n
USE_QT=		concurrent core dbus declarative gui location network printsupport \
		sql webchannel webengine widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	xcb

USE_LDCONFIG=	yes

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_PySide2

OPTIONS_DEFINE=	GNOMEKEYRING KDEINTEGRATION
OPTIONS_DEFAULT=	KDEINTEGRATION
OPTIONS_SUB=	YES

KDEINTEGRATION_CMAKE_BOOL=	ENABLE_KDE_FRAMEWORKS_INTEGRATION_PLUGIN
KDEINTEGRATION_USE=		KDE=completion,config,coreaddons,crash,jobwidgets,kio,purpose,service,wallet,widgetsaddons

GNOMEKEYRING_CMAKE_BOOL=	BUILD_KEYRING
GNOMEKEYRING_USE=		GNOME=glib20
GNOMEKEYRING_USES=		gnome pkgconfig
GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring

.include <bsd.port.mk>
