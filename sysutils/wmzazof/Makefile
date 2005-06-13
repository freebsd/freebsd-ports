# New ports collection makefile for:	wmzazof
# Date created:				Sat Oct  6 18:44:32 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmzazof
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://users.chello.be/cr49940//wmzazof/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A simple dockapp that displays the uptime, free and used memory

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmzazof ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif #NOPORTDOCS

.include <bsd.port.mk>
