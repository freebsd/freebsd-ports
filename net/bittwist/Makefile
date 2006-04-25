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
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		bittwist.1 bittwistb.1 bittwiste.1

.include <bsd.port.pre.mk>

# 5.3 is the first version to have round().
.if ${OSVERSION} < 503001
IGNORE=	does not build under 5.2 and older (no round())
.endif

# 5.3 and up do not have a new enough libpcap but does have round().
# 6.0 and up have both a new enough libpcap and round().
.if ${OSVERSION} >= 503001 && ${OSVERSION} < 600100
BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

.include <bsd.port.post.mk>
