PORTNAME=	plasma-workspace-wallpapers
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 wallpapers

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL3

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		buildtools_build \
		qmake_build

NO_ARCH=	yes

.include <bsd.port.mk>
