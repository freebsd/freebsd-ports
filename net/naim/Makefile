# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.11.4.13
CATEGORIES=	net
MASTER_SITES=	http://www.acm.rpi.edu/~n/naim/

MAINTAINER=	rtdean@cytherianage.net

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/p1//}
GNU_CONFIGURE=	yes

MAN1=		naim.1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naim.hlp ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/COLORS ${DOCSDIR}
.endif

.include <bsd.port.mk>
