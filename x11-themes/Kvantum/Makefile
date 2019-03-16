# $FreeBSD$

PORTNAME=	Kvantum
DISTVERSIONPREFIX=	V
DISTVERSION=	0.10.9
PORTREVISION=	1
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	-qt5

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	SVG-based theme engine for Qt, KDE and LXQt

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang kde:5 qmake qt:5
USE_XORG=	x11 xext
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	tsujan
USE_KDE=	windowsystem
USE_QT=		core gui svg widgets x11extras buildtools_build \
		linguisttools_build

WRKSRC_SUBDIR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/kde4/|/|g' ${WRKSRC}/style/style.pro
	@${REINPLACE_CMD} -e 's|/kde4/|/|g' -e 's|--no-preserve=mode||g' \
		${WRKSRC}/themes/themes.pro

.include <bsd.port.mk>
