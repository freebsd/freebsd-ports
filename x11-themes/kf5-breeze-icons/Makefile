# $FreeBSD$

PORTNAME=	breeze-icons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Breeze icon theme for KDE

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING-ICONS

USES=		cmake:outsource kde:5 tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build core qmake_build testlib

NO_ARCH=	yes

.include <bsd.port.mk>
