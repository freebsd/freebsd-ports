# New ports collection makefile for:	SS
# Version required:			1.3.3
# Date created:				5 January 1997
# Whom:					Pedro Giffuni
#
# $Id: Makefile,v 1.3 1998/02/20 18:39:55 steve Exp $
#

DISTNAME=	ss_1.3.3
PKGNAME=	ss-1.3.3
CATEGORIES=	math
MASTER_SITES=	http://www.irus.rri.on.ca/~amulder/ss/

MAINTAINER=	giffunip@asme.org

WRKSRC=		${WRKDIR}/ss_133
MAN1=		ss.1 pss.1

do-configure:
	@${CP} ${WRKSRC}/config.bsd  ${WRKSRC}/config.h

.include <bsd.port.mk>
