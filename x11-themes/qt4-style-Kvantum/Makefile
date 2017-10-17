# $FreeBSD$

PORTNAME=	Kvantum
PORTVERSION=	0.10.4
DISTVERSIONPREFIX=	V
PORTREVISION=	2
CATEGORIES=	x11-themes
PKGNAMEPREFIX=	qt4-style-

MAINTAINER=	rezny@FreeBSD.org
COMMENT=	SVG-based theme engine for Qt4/5, KDE and LXQT

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan

USES=		compiler:c++11-lang qmake
USE_QT4=	corelib gui svg rcc_build uic_build moc_build
USE_XORG=	x11 xext

WRKSRC_SUBDIR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/kde4/|/|g' ${WRKSRC}/style/style.pro
	@${REINPLACE_CMD} -e 's|/kde4/|/|g' -e 's|--no-preserve=mode||g' \
		${WRKSRC}/themes/themes.pro

.include <bsd.port.mk>
