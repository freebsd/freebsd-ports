PORTNAME=	networkmanager-qt
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	net-mgmt kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt wrapper for NetworkManager API

BUILD_DEPENDS=	networkmanager-shim>=1.4.0:net-mgmt/networkmanager-shim

LICENSE=	BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE	= ${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_CC0-1.0	= ${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_GPLv2	= ${WRKSRC}/LICENSES/GPL-2.0-only.txt
LICENSE_FILE_GPLv3	= ${WRKSRC}/LICENSES/GPL-3.0-only.txt
LICENSE_FILE_LGPL21	= ${WRKSRC}/LICENSES/LGPL-2.1-only.txt
LICENSE_FILE_LGPL3	= ${WRKSRC}/LICENSES/LGPL-3.0-only.txt

USES=		cmake compiler:c++11-lang kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	auth config configwidgets i18n iconthemes kcmutils package \
		plasma-workspace \
		ecm:build
USE_QT=		base
USE_XORG=	x11

CMAKE_ARGS=	-DKF_IGNORE_PLATFORM_CHECK=true

.include <bsd.port.mk>
