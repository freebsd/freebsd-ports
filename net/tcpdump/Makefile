# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpdump
PORTVERSION=	4.9.3
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcap.so.1:net/libpcap

USES=		gmake

GNU_CONFIGURE=	yes
UNPRIV_USER?=	tcpdump
CHROOTDIR?=	/var/run/tcpdump

OPTIONS_DEFINE=	CRYPTO SMB SMI USER CHROOT
OPTIONS_DEFAULT=	CRYPTO SMB SMI

CRYPTO_DESC=	Support IPSEC and TCPMD5
# This one is intentionally worded this way because the default
# description implies that tcpdump would not capture SMB, which
# is not true. It will just not print it if this option is off.
SMB_DESC=	Support printing SMB information
SMI_DESC=	Allow MIBs to be loaded on the fly
USER_DESC=	Drop privileges to dedicated user
CHROOT_DESC=	Chroot to /var/run/tcpdump (set CHROOTDIR to change)

CRYPTO_USES=		ssl
CRYPTO_CONFIGURE_WITH=	crypto
SMB_CONFIGURE_ENABLE=	smb
SMI_CONFIGURE_WITH=	smi
SMI_LIB_DEPENDS=	libsmi.so:net-mgmt/libsmi
USER_CONFIGURE_ON=	--with-user=${UNPRIV_USER}
USER_VARS=		USERS=${UNPRIV_USER} GROUPS=${UNPRIV_USER}
CHROOT_CONFIGURE_ON=	--with-chroot=${CHROOTDIR}

PLIST_FILES=	sbin/tcpdump \
		man/man1/tcpdump.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,sys/capability.h,sys/capsicum.h,' \
		${WRKSRC}/tcpdump.c

post-configure:
	@${REINPLACE_CMD} -e "s,\./\.\./${LIBPCAP_FORCE_VER}/libpcap\.a,${LOCALBASE}/lib/libpcap.so.1," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${STAGEDIR}/${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${STAGEDIR}/${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
