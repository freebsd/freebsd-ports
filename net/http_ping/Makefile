# New ports collection makefile for:	http_ping
# Date created:			11 August 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	http_ping
PORTVERSION=	20020403
CATEGORIES=	net www
MASTER_SITES=	http://www.acme.com/software/http_ping/
DISTNAME=	${PORTNAME}_03apr2002

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Sends HTTP requests every few seconds and times how long they take

WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		http_ping.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/http_ping

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/http_ping ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/http_ping.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
