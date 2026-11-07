PORTNAME=	falkon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	www kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser based on Webengine and Qt Framework
WWW=		https://www.falkon.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake desktop-file-utils gettext kde:6 qt:6 ssl tar:xz xorg
USE_KDE=	archive i18n \
		ecm:build
USE_QT=		base declarative webchannel webengine \
		sqldriver-sqlite:run
USE_XORG=	x11 xcb

USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_PYTHON_SUPPORT

FLAVORS=	kf6 qt6
FLAVOR?=	kf6

kf6_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_PKGNAMESUFFIX=		-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

.if ${FLAVOR} != qt6
USE_KDE+=	coreaddons crash jobwidgets kio purpose wallet
PLIST_SUB=	KDEINTEGRATION=""
.else
CMAKE_ON+=	CMAKE_DISABLE_FIND_PACKAGE_KF6CoreAddons
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
