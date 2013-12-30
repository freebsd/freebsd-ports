# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpdump
PORTVERSION=	4.5.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool

LIB_DEPENDS=	pcap:${PORTSDIR}/net/libpcap

GNU_CONFIGURE=		yes
USE_GMAKE=		yes

UNPRIV_USER?=	nobody
CHROOTDIR?=	/var/run/tcpdump

OPTIONS_DEFINE=	CRYPTO IPV6 SMB SMI USER CHROOT
OPTIONS_DEFAULT=	CRYPTO IPV6 SMB SMI

CRYPTO_DESC=	Support IPSEC and TCPMD5
# This one is intentionally worded this way because the default
# description implies that tcpdump would not capture SMB, which
# is not true. It will just not print it if this option is off.
SMB_DESC=	Support printing SMB information
SMI_DESC=	Allow MIBs to be loaded on the fly
USER_DESC=	Drop privileges to nobody
CHROOT_DESC=	Chroot to /var/run/tcpdump (set CHROOTDIR to change)

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--enable-pcap_setdirection --with-pcap_setdirection

# The --without-crypto flag needs to be explicitly specified. The
# configure script gets confused if you specify --with-crypto and
# thinks this means you *don't* want crypto.
#
.if ${PORT_OPTIONS:MCRYPTO}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--without-crypto
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if empty(PORT_OPTIONS:MSMB)
CONFIGURE_ARGS+=	--disable-smb
.endif

.if ${PORT_OPTIONS:MSMI}
LIB_DEPENDS+=		smi:${PORTSDIR}/net-mgmt/libsmi
.else
CONFIGURE_ARGS+=	--disable-smi
.endif

.if ${PORT_OPTIONS:MUSER}
CONFIGURE_ARGS+=	--with-user=${UNPRIV_USER}
.endif

.if ${PORT_OPTIONS:MCHROOT}
CONFIGURE_ARGS+=	--with-chroot=${CHROOTDIR}
.endif

.include <bsd.port.pre.mk>

PLIST_FILES=	sbin/tcpdump \
		man/man1/tcpdump.1.gz

post-configure:
	@${REINPLACE_CMD} -e "s,\./\.\./${LIBPCAP_FORCE_VER}/libpcap\.a,${LOCALBASE}/lib/libpcap.so.1," ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${STAGEDIR}/${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${STAGEDIR}/${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
