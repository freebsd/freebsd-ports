# New ports collection makefile for:	icmpchat
# Date created:				8 October 2002
# Whom:					mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	icmpchat
PORTVERSION=	0.6
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	icmpchat

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple console-based chat that uses the ICMP protocol

pre-patch:
	@${REINPLACE_CMD} -e 's|-O2 -Wall -pedantic|${CFLAGS}|;\
		s|= gcc|?= gcc|;s|default|all|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpchat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/License ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Problems ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Todo ${DOCSDIR}
.endif

.include <bsd.port.mk>
