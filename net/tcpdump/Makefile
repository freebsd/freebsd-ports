# New ports collection makefile for:	tcpdump
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcpdump
PORTVERSION=	3.8.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool

# TODO: Add strict sanity check that we're compiling against a
# version of libpcap with which this tcpdump release is compatible.
#
.if defined(TCPDUMP_OVERWRITE_BASE) || !defined(WITH_LIBPCAP_BASE)
LIB_DEPENDS=	pcap.2:${PORTSDIR}/net/libpcap
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		tcpdump.1

GNU_CONFIGURE=		yes

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

# Compilation Options
#
# Special options:
# TCPDUMP_OVERWRITE_BASE	Overwrite the base system's tcpdump binary.
#				Implies the use of the libpcap port.
#
# User-definable switches:
# WITHOUT_CRYPTO	Build without IPSEC or TCPMD5 decryption.
# WITHOUT_IPV6		Build without IPV6 support.
# WITH_LIBPCAP_BASE	Use libpcap from the base system instead of ports.
# WITH_RADIOTAP		Build with support for BSD 802.11 Radiotap headers.
# WITH_TCPMD5		Build with support for TCP-MD5 digest verification.
#
# Defaults:	WITHOUT_LIBPCAP_PORT WITHOUT_RADIOTAP WITHOUT_TCPMD5
#		WITH_CRYPTO WITH_IPV6

# The --without-crypto flag needs to be explicitly specified. The
# configure script gets confused if you specify --with-crypto and
# thinks this means you *don't* want crypto.
# If crypto is requested, then apply a patch to fix the detection
# of OpenSSL versions > 0.9.7d. We assume the installed version is
# at least this recent; this may fail on older systems.
#
.if defined(WITHOUT_CRYPTO)
CONFIGURE_ARGS+=	--without-crypto
.else
USE_OPENSSL=		defined
USE_AUTOCONF_VER?=	253
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-openssl-configure.in
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_RADIOTAP)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-extract.h \
		${PATCHDIR}/extra-patch-ieee802_11_radio.h \
		${PATCHDIR}/extra-patch-print-802_11.c
.endif

.if defined(WITH_TCPMD5)
.if defined(WITHOUT_CRYPTO)
BROKEN=		"The use of WITH_TCPMD5 requires crypto support."
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-tcpmd5-print-tcp.c \
		${PATCHDIR}/extra-patch-tcpmd5-tcp.h
.endif
.endif

# When compiling against the port, it's necessary to force the
# port to look for libpcap in ${LOCALPCAPBASE} first, for both
# the configure and build steps.
#
.if defined(TCPDUMP_OVERWRITE_BASE) || !defined(WITH_LIBPCAP_BASE)
LOCALPCAPBASE=	${LOCALBASE}
CONFIGURE_ENV+=	CFLAGS="-L${LOCALPCAPBASE}/lib"
.else
LOCALPCAPBASE=	/usr
.endif

LOCALPCAPFILES=	include/pcap.h include/pcap-namedb.h include/pcap-bpf.h \
		lib/libpcap.a
WRKPCAPDIR=	${WRKDIR}/libpcap-0.8.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 503000
BROKEN=		"Broken dependency"
.endif

# When building tcpdump against a particular pcap version, it expects to
# find a built, untarred source tree in the parent of the work tree.
# Build a symlink farm which points to the installed versions of the
# required files, in order to produce the files it wants without
# requiring that the libpcap distfile be untarred.
#
pre-configure:
	${MKDIR} ${WRKPCAPDIR}
.for i in ${LOCALPCAPFILES}
	${LN} -s ${LOCALPCAPBASE}/$i ${WRKPCAPDIR}
.endfor

.if defined(TCPDUMP_OVERWRITE_BASE)
post-install:
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
