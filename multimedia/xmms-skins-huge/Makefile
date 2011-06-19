# New ports collection makefile for:	xmms-skins-huge
# Date created:				2011-06-18
# Whom:					Jesse <jessefrgsmith@yahoo.ca>
#
# $FreeBSD$
#

PORTNAME=	xmms-skins-huge
PORTVERSION=	1.0.0
CATEGORIES=	multimedia
MASTER_SITES=	http://webs.ono.com/supercarlos/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Skins for X Multimedia System (XMMS)

CONFLICTS_INSTALL=	xmms-skins-[0-9]*

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Skins
DATADIR=	${PREFIX}/share/xmms

do-install:
	${MKDIR} ${DATADIR}/Skins
	${INSTALL_DATA} ${WRKSRC}/* ${DATADIR}/Skins

.include <bsd.port.mk>
