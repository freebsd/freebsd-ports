PORTNAME=	Kvantum
DISTVERSION=	1.1.0
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/tsujan/${PORTNAME}/releases/download/V${DISTVERSION}/
PKGNAMESUFFIX=	-qt6

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	SVG-based theme engine for Qt, KDE and LXQt
WWW=		https://github.com/tsujan/Kvantum

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gl kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	windowsystem
USE_LDCONFIG=	yes
USE_QT=		base svg
USE_XORG=	ice sm x11 xext

WRKSRC_SUBDIR=	${PORTNAME}

.include <bsd.port.mk>
