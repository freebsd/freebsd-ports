# New ports collection makefile for:	tcpdump
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcpdump
PORTVERSION=	3.8.1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/beta/
DISTNAME=	${PORTNAME}-${PORTVERSION}-316

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool

BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		tcpdump.1

GNU_CONFIGURE=	yes


.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITHOUT_CRYPTO)
CONFIGURE_ARGS+=	--without-crypto
.endif

.include <bsd.port.mk>
