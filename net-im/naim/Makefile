# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.11.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://rpi-acm.org/~n/dev.n.ml.org/ \
		http://www.acm.rpi.edu/~n/dev.n.ml.org/

MAINTAINER=	rtdean@cytherianage.net

GNU_CONFIGURE=	yes

MAN1=		naim.1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naim.hlp ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/COLORS ${DOCSDIR}
.endif

.include <bsd.port.mk>
