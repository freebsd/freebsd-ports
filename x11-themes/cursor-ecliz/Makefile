# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	ecliz
PORTVERSION=	0.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	cursor-
DISTNAME=	76605-Ecliz_Port

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Ecliz X cursor theme

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Ecliz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/icons/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} cursors \
		${STAGEDIR}${PREFIX}/lib/X11/icons/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/index.theme \
		${STAGEDIR}${PREFIX}/lib/X11/icons/${PORTNAME}

.include <bsd.port.mk>
