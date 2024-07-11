PORTNAME=	kirigami-addons
DISTVERSION=	1.3.0
CATEGORIES=	x11-toolkits kde
MASTER_SITES=	KDE/stable/${PORTNAME}/
DIST_SUBDIR=	KDE
PKGNAMESUFFIX=	-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component library for KDE Kirigami
WWW=		https://api.kde.org/frameworks/kirigami-addons/html/

LICENSE=	LGPL20

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl
USE_KDE=	config i18n kirigami2 \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
