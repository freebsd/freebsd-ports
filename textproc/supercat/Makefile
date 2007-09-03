# New ports collection makefile for:	supercat
# Date created:		3 September 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	supercat
PORTVERSION=	0.5.1
CATEGORIES=	textproc
MASTER_SITES=	http://supercat.nosredna.net/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Regexp-based text colorizer with ASCII/HTML output

GNU_CONFIGURE=	yes
MAN1=		spc.1
PORT_VERBS=	${PORTNAME} spc

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/supercat|${ETCDIR}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|c:C:dDhmnrt:vS|&Rw|' ${WRKSRC}/src/spc.c

.include <bsd.port.mk>
