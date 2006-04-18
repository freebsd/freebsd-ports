# New ports collection makefile for:	bittwist
# Date created:			17 April 2006
# Whom:				Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	bittwist
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-bsd-${PORTVERSION}

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Libpcap-based Ethernet packet generator, with PCAP editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		bittwist.1 bittwistb.1 bittwiste.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build under 4.x
.endif

.include <bsd.port.post.mk>
