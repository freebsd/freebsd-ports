# $FreeBSD$

PORTNAME=	bittwist
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/_BSD/Bit-Twist%20${PORTVERSION}
DISTNAME=	${PORTNAME}-bsd-${PORTVERSION}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Libpcap-based Ethernet packet generator, with PCAP editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake

PLIST_FILES=	bin/bittwist bin/bittwistb bin/bittwiste \
		man/man1/bittwist.1.gz \
		man/man1/bittwistb.1.gz \
		man/man1/bittwiste.1.gz

.include <bsd.port.mk>
