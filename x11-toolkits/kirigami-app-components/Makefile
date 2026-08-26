PORTNAME=	kirigami-app-components
DISTVERSION=	1.0.2
CATEGORIES=	x11-toolkits kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kirigami addons and modules
WWW=		https://invent.kde.org/libraries/kirigami-app-components

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
USE_KDE=	config guiaddons kirigami2 i18n \
		ecm:build
USE_QT=		base declarative
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
