# ex:ts=8
# Ports collection makefile for:  jive
# Version required:     	  1.0
# Date created:			  Mon Feb 17, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	jive-1.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
#MASTER_SITE_SUBDIR= games/amusements
MASTER_SITE_SUBDIR= Incoming

MAINTAINER=     obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/jive
MAN1=		jive.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1


.include <bsd.port.mk>
