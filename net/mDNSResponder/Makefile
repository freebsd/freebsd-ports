# Created by: Alfred Perlstein <alfred@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mDNSResponder
PORTVERSION=	765.20.4
CATEGORIES=	net dns
MASTER_SITES=	http://opensource.apple.com/tarballs/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bonjour (zero-configuration networking) by Apple

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual

# lib/libdns_sd.so.1 sbin/mdnsd
CONFLICTS_INSTALL=	avahi-libdns- openmdns-

OPTIONS_DEFINE=	IPV6

ALL_TARGET=	all dnsextd
BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
MAKE_ARGS=	LDCONFIG=${TRUE} LOCALBASE=${PREFIX} MAN_PATH=${MANPREFIX}/man STRIP=${STRIP_CMD} os=freebsd
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	mdnsd mdnsresponderposix
USES=		cpe gmake

CPE_VENDOR=	apple
CPE_PRODUCT=	${PORTNAME:tl}

EXTRA_BIN=	mDNSClientPosix mDNSIdentify mDNSNetMonitor mDNSProxyResponderPosix mDNSResponderPosix
EXTRA_MAN1=	dns-sd.1
EXTRA_MAN8=	dnsextd.8 mDNSResponderPosix.8
EXTRA_SBIN=	dnsextd

post-patch:
	@${REINPLACE_CMD} -e 's|\(#define IPV6_2292_PKTINFO \).*|\1IPV6_PKTINFO|; s|\(#define IPV6_2292_HOPLIMIT \).*|\1IPV6_HOPLIMIT|' ${WRKSRC}/mDNSPosix/mDNSUNP.h
	@${MV} ${WRKSRC}/mDNSShared/mDNSResponder.8 ${WRKSRC}/mDNSShared/mDNSResponderPosix.8

post-patch-IPV6-off:
	@${REINPLACE_CMD} -e '/^CFLAGS_OS/ s|-DHAVE_IPV6|-UHAVE_IPV6|' ${WRKSRC}/mDNSPosix/Makefile

post-install:
	cd ${WRKSRC}/mDNSPosix/build/prod/ && ${INSTALL_PROGRAM} ${EXTRA_BIN} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/mDNSShared/ && ${INSTALL_MAN} ${EXTRA_MAN1} ${STAGEDIR}${PREFIX}/man/man1/
	cd ${WRKSRC}/mDNSShared/ && ${INSTALL_MAN} ${EXTRA_MAN8} ${STAGEDIR}${PREFIX}/man/man8/
	cd ${WRKSRC}/mDNSPosix/build/prod/ && ${INSTALL_PROGRAM} ${EXTRA_SBIN} ${STAGEDIR}${PREFIX}/sbin/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dns-sd

.include <bsd.port.mk>
