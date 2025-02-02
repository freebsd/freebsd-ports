PORTNAME=	kdiff3
DISTVERSION=	1.11.5
PORTREVISION=	1
CATEGORIES=	textproc kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graphical frontend for diff
WWW=		https://kdiff3.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

USES=		cmake compiler:c++11-lang gettext-tools:build kde:6 qt:6 tar:xz \
		xorg
USE_KDE=	config coreaddons crash i18n kio widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		5compat base
USE_XORG=	x11

CMAKE_ARGS=	-DBUILD_WITH_QT6=ON

DOCSDIR_REL=	share/doc/HTML

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
