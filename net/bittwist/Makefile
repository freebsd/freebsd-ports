# New ports collection makefile for:	bittwist
# Date created:			17 April 2006
# Whom:				Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	bittwist
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-bsd-${PORTVERSION}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Libpcap-based Ethernet packet generator, with PCAP editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKE_JOBS_SAFE=	yes

MAN1=		bittwist.1 bittwistb.1 bittwiste.1
PLIST_FILES=	bin/bittwist bin/bittwistb bin/bittwiste

.include <bsd.port.mk>
