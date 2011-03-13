# New ports collection makefile for:	wmzazof
# Date created:				Sat Oct  6 18:44:32 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmzazof
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://members.chello.be/cr49940/wmzazof/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple dockapp that displays the uptime, free and used memory

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

USE_XORG=	xpm

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmzazof ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif #NOPORTDOCS

.include <bsd.port.mk>
