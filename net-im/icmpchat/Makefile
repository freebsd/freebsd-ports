# New ports collection makefile for:	ICMP-Chat
# Date created:				8 October 2002
# Whom:					Matthew West <mwest@uct.ac.za>
#
# $FreeBSD$
#

PORTNAME=	icmpchat
PORTVERSION=	0.6
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple console-based chat that uses ICMP protocol

pre-patch:
	@${REINPLACE_CMD} -e 's|-O2 -Wall -pedantic|${CFLAGS}|;\
		s|= gcc|?= gcc|;s|default|all|' ${WRKSRC}/Makefile
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e \
		's|((uint8_t \*) data) +=|data += sizeof(uint8_t *) *|' \
			${WRKSRC}/sha256.c

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
