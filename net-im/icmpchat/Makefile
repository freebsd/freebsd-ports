# New ports collection makefile for:	icmpchat
# Date created:				8 October 2002
# Whom:					mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	icmpchat
PORTVERSION=	0.5.1
CATEGORIES=	net
MASTER_SITES=	http://www.codito.de/prog/

MAINTAINER=	mwest@uct.ac.za

USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|-O3 -Wall|${CFLAGS}|;s|= gcc|?= gcc|; \
		s|default|all|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpchat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} -m 555 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
