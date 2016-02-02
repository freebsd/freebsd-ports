# $FreeBSD$

PORTNAME=	E17
PORTVERSION=	20151119
CATEGORIES=	x11-themes enlightenment
MASTER_SITES=	http://gnome-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-theme
DISTNAME=	163472-${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	matthew@reztek.cz
COMMENT=	Dark GTK theme for Enlightenment

USES=		tar:xz
NO_ARCH=	yes
NO_BUILD=	yes
THEME_NAME=	E17gtk
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
WRKSRC=		${WRKDIR}/${THEME_NAME}

do-install:
	@${MKDIR} ${STAGEDIR}${THEME_DIR}
.for dir in gtk-2.0 gtk-3.0
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${THEME_DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/index.theme ${STAGEDIR}${THEME_DIR}

.include <bsd.port.mk>
