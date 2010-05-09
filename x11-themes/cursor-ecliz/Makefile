# New ports collection makefile for:	cursor-ecliz
# Date created:		2009-11-13
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	ecliz
PORTVERSION=	0.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	cursor-
DISTNAME=	76605-Ecliz_Port

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Ecliz X cursor theme

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Ecliz

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} cursors ${PREFIX}/lib/X11/icons/${PORTNAME}
	${CP} ${WRKSRC}/index.theme ${PREFIX}/lib/X11/icons/${PORTNAME}

.include <bsd.port.mk>
