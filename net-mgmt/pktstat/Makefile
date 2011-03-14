# New ports collection makefile for:	pktstat
# Date created:		5 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pktstat
PORTVERSION=	1.8.4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.adaptive-enterprises.com.au/~d/software/pktstat/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network traffic viewer

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

GNU_CONFIGURE=	yes
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} '/struct arphdr/d' ${WRKSRC}/ether.c
	@${REINPLACE_CMD} -e 's/IPPORT_USERRESERVED/IPPORT_RESERVED/' ${WRKSRC}/tcp.c

.include <bsd.port.mk>
