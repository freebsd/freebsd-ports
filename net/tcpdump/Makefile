# New ports collection makefile for:	tcpdump
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcpdump
PORTVERSION=	4.0.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcpdump.org/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool

LIB_DEPENDS=	pcap.3:${PORTSDIR}/net/libpcap \
		smi.2:${PORTSDIR}/net-mgmt/libsmi

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
MAKE_JOBS_SAFE=	yes

# Compilation Options
#
# User-definable switches:
# WITHOUT_CRYPTO	Build without IPSEC or TCPMD5 decryption.
# WITHOUT_IPV6		Build without IPV6 support.
#
# Defaults:	WITH_CRYPTO WITH_IPV6

# The --without-crypto flag needs to be explicitly specified. The
# configure script gets confused if you specify --with-crypto and
# thinks this means you *don't* want crypto.
#
.if defined(WITHOUT_CRYPTO)
CONFIGURE_ARGS+=	--without-crypto
.else
USE_OPENSSL=		defined
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

CONFIGURE_ARGS+=	--disable-smb

MAN1=		tcpdump.1
PLIST_FILES=	sbin/tcpdump

#
# Force the use of the shared library from the libpcap port.
# Don't rely on pcap-config, it is still not ready for prime time.
#
# When building tcpdump against a particular pcap version, it expects to
# find a built, untarred source tree in the parent of the work tree.
# Build a symlink farm which points to the installed versions of the
# required files, in order to produce the files it wants without
# requiring that the libpcap distfile be untarred.
# Furthermore, tcpdump's aclocal.m4 only looks for the static version
# of this library, so we need to perform another substitution.
#
CFLAGS+=		"-I${LOCALBASE}/include"
LDFLAGS+=		"-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

LIBPCAP_FORCE_VER=	libpcap-1.0.0
LOCALPCAPFILES=	include/pcap.h include/pcap-namedb.h include/pcap-bpf.h \
		include/pcap lib/libpcap.a
WRKPCAPDIR=	${WRKDIR}/${LIBPCAP_FORCE_VER}

pre-configure:
	@${MKDIR} ${WRKPCAPDIR}
.for i in ${LOCALPCAPFILES}
	@${LN} -s ${LOCALBASE}/$i ${WRKPCAPDIR}
.endfor

post-configure:
	@${REINPLACE_CMD} -e "s,\./\.\./${LIBPCAP_FORCE_VER}/libpcap\.a,${LOCALBASE}/lib/libpcap.so.3," ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
