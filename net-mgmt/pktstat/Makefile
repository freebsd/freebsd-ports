# New ports collection makefile for:	pktstat
# Date created:		5 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pktstat
PORTVERSION=	1.8.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.adaptive-enterprises.com.au/~d/software/pktstat/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Network traffic viewer

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} '/struct arphdr/d' ${WRKSRC}/ether.c
	@${REINPLACE_CMD} -e 's/IPPORT_USERRESERVED/IPPORT_RESERVED/' ${WRKSRC}/tcp.c

.include <bsd.port.mk>
