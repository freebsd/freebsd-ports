# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	ecliz
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	cursor-
DISTNAME=	76605-Ecliz_Port

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ecliz X cursor theme

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Ecliz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} cursors \
		${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/index.theme \
		${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}

.include <bsd.port.mk>
