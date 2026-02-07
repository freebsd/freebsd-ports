PORTNAME=	kdiff3
DISTVERSION=	1.12.3
CATEGORIES=	textproc kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graphical frontend for diff
WWW=		https://apps.kde.org/kdiff3/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl # GLX
USE_KDE=	colorscheme completion config configwidgets coreaddons crash \
		i18n jobwidgets kio service solid widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
