# New ports collection makefile for:	SS
# Version required:			1.3.3
# Date created:				5 January 1997
# Whom:					pgiffuni@FPS.biblos.unal.edu.co
#
# $Id: Makefile,v 1.1.1.1 1997/01/24 11:45:39 max Exp $
#

DISTNAME=	ss_1.3.3
PKGNAME=	ss-1.3.3
CATEGORIES=	math
MASTER_SITES=	http://www.ualberta.ca/~amulder/ss/

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

WRKSRC=		${WRKDIR}/ss_133
MAN1=		ss.1 pss.1

do-configure:
	@${CP} ${WRKSRC}/config.bsd  ${WRKSRC}/config.h

.include <bsd.port.mk>
