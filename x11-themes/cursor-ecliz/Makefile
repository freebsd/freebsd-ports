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

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} cursors ${PREFIX}/lib/X11/icons/${PORTNAME}
	${CP} ${WRKSRC}/index.theme ${PREFIX}/lib/X11/icons/${PORTNAME}

.include <bsd.port.mk>
