# $FreeBSD$

PORTNAME=	E17
PORTVERSION=	3.22.1
DISTVERSIONPREFIX=	V
PORTEPOCH=	1
CATEGORIES=	x11-themes enlightenment
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-theme

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dark GTK theme for Enlightenment

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan
GH_PROJECT=	E17gtk

NO_ARCH=	yes
NO_BUILD=	yes
THEME_DIR=	${PREFIX}/share/themes/${GH_PROJECT}

do-install:
	@${MKDIR} ${STAGEDIR}${THEME_DIR}
.for dir in gtk-2.0 gtk-3.0
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${THEME_DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/index.theme ${STAGEDIR}${THEME_DIR}

.include <bsd.port.mk>
