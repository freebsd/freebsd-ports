# $FreeBSD$

PORTNAME=	Kvantum
DISTVERSIONPREFIX=	V
DISTVERSION=	0.12.1
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	-qt5

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	SVG-based theme engine for Qt, KDE and LXQt

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gl kde:5 qmake qt:5 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan

USE_GL=		gl
USE_LDCONFIG=	yes
USE_KDE=	windowsystem
USE_QT=		core gui svg widgets x11extras buildtools_build \
		linguisttools_build
USE_XORG=	x11 xext

WRKSRC_SUBDIR=	${PORTNAME}

.include <bsd.port.mk>
