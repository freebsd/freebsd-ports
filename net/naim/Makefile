# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.11.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.acm.rpi.edu/~n/naim/ \
		http://128.113.139.111/~n/.naim_archive/0/11/

MAINTAINER=	rtdean@cytherianage.net

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--build=${CONFIGURE_TARGET} \
		--disable-nirc-manlink

MAN1=		naim.1
MLINKS=		naim.1 nirc.1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naim.hlp ${DOCSDIR}
.endif

.include <bsd.port.mk>
