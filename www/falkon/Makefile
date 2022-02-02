PORTNAME=	falkon
DISTVERSION=	3.2.0
CATEGORIES=	www
MASTER_SITES=	KDE/stable/falkon/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser based on Webengine and Qt Framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake desktop-file-utils kde:5 qt:5 ssl tar:xz xorg
USE_KDE=	archive i18n \
		ecm_build
USE_QT=		concurrent core dbus declarative gui location network printsupport \
		sql webchannel webengine widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	xcb

USE_LDCONFIG=	yes

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_PySide2

FLAVORS=	default qtonly
FLAVOR?=	default

default_CONFLICTS_INSTALL=	${PORTNAME}-qtonly
qtonly_PKGNAMESUFFIX=		-qtonly
qtonly_CONFLICTS_INSTALL=	${PORTNAME}

.if ${FLAVOR} != qtonly
CMAKE_ON+=	ENABLE_KDE_FRAMEWORKS_INTEGRATION_PLUGIN
USE_KDE+=	completion config coreaddons crash jobwidgets kio purpose service solid wallet widgetsaddons windowsystem
PLIST_SUB=	KDEINTEGRATION=""
.else
PLIST_SUB=	KDEINTEGRATION="@comment "
COMMENT=	Web browser based on WebEngine (no integration with KDE Plasma)
.endif

OPTIONS_DEFINE=	GNOMEKEYRING
OPTIONS_SUB=	YES

GNOMEKEYRING_CMAKE_BOOL=	BUILD_KEYRING
GNOMEKEYRING_USE=		GNOME=glib20
GNOMEKEYRING_USES=		gnome pkgconfig
GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring

.include <bsd.port.mk>
