# New ports collection makefile for:	tcpdump
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcpdump
PORTVERSION=	3.8.3
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool

.if defined(TCPDUMP_OVERWRITE_BASE)
LIB_DEPENDS=	pcap.2:${PORTSDIR}/net/libpcap
.else
BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		tcpdump.1

GNU_CONFIGURE=	yes

.if defined(TCPDUMP_OVERWRITE_BASE)
PREFIX=		/usr
PKGNAMESUFFIX=	-overwrite-base
MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man
PLIST_SUB+=	NOTBASE="@comment "
PLIST_SUB+=	BASE=""
PKGMESSAGE=	${FILESDIR}/pkg-message-base
.else
PLIST_SUB+=	BASE="@comment "
PLIST_SUB+=	NOTBASE=""
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITHOUT_CRYPTO)
CONFIGURE_ARGS+=	--without-crypto
.endif

.if defined(WITH_RADIOTAP)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-extract.h \
		${PATCHDIR}/extra-patch-ieee802_11_radio.h \
		${PATCHDIR}/extra-patch-print-802_11.c
.endif

.if defined(WITH_TCPMD5)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-tcpmd5-print-tcp.c \
		${PATCHDIR}/extra-patch-tcpmd5-tcp.h
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

.if defined(TCPDUMP_OVERWRITE_BASE)
post-install:
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
