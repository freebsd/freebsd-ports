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

.if defined(WITH_RADIOTAP)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile.in \
		${PATCHDIR}/extra-patch-cpack.c \
		${PATCHDIR}/extra-patch-cpack.h \
		${PATCHDIR}/extra-patch-extract.h \
		${PATCHDIR}/extra-patch-ieee802_11_radio.h \
		${PATCHDIR}/extra-patch-print-802_11.c
.endif

LOCALPCAPDIR=	${WRKDIR}/libpcap-0.8.1
LOCALPCAPFILES= include/pcap.h include/pcap-namedb.h include/pcap-bpf.h \
		lib/libpcap.a

#
# When building tcpdump against a particular pcap version, it expects to
# find a built, untarred source tree in the parent of the work tree.
# Build a symlink farm to produce the files it wants without requiring
# pcap to be untarred.
#
pre-configure:
	${MKDIR} ${LOCALPCAPDIR}
.for i in ${LOCALPCAPFILES}
	${LN} -s ${LOCALBASE}/$i ${LOCALPCAPDIR}
.endfor

.include <bsd.port.mk>
