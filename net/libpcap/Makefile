# New ports collection makefile for:	libpcap
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpcap
PORTVERSION=	0.8.1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/beta/
DISTNAME=	${PORTNAME}-${PORTVERSION}-316

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Ubiquitous network traffic capture library

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN3=		pcap.3

GNU_CONFIGURE=	yes

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !defined(WITH_DAG)
CONFIGURE_ARGS+=	--without-dag
.endif

.include <bsd.port.mk>
