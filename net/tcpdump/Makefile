# New ports collection makefile for:	tcpdump
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcpdump
PORTVERSION=	4.2.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool

LIB_DEPENDS=	pcap.1:${PORTSDIR}/net/libpcap

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	CRYPTO "Support IPSEC and TCPMD5" On \
		IPV6 "Support IPV6" On \
		SMB "Support SMB printer" On \
		SMI "Allow MIBs to be loaded on the fly" On \
		USER "Drop privileges to nobody" Off \
		CHROOT "Chroot support" Off

UNPRIV_USER?=	nobody
CHROOTDIR?=	/var/run/tcpdump

.include <bsd.port.options.mk>
# The --without-crypto flag needs to be explicitly specified. The
# configure script gets confused if you specify --with-crypto and
# thinks this means you *don't* want crypto.
#
.if defined(WITHOUT_CRYPTO)
CONFIGURE_ARGS+=	--without-crypto
.else
USE_OPENSSL=	yes
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITHOUT_SMB)
CONFIGURE_ARGS+=	--disable-smb
.endif

.if defined(WITHOUT_SMI)
CONFIGURE_ARGS+=	--disable-smi
.else
LIB_DEPENDS+=		smi.2:${PORTSDIR}/net-mgmt/libsmi
.endif

.if defined(WITH_USER)
CONFIGURE_ARGS+=	--with-user=${UNPRIV_USER}
.endif

.if defined(WITH_CHROOT)
CONFIGURE_ARGS+=	--with-chroot=${CHROOTDIR}
.endif

.include <bsd.port.pre.mk>

MAN1=		tcpdump.1
PLIST_FILES=	sbin/tcpdump

post-configure:
	@${REINPLACE_CMD} -e "s,\./\.\./${LIBPCAP_FORCE_VER}/libpcap\.a,${LOCALBASE}/lib/libpcap.so.1," ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
