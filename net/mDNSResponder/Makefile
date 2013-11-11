# Created by: Alfred Perlstein <alfred@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mDNSResponder
PORTVERSION=	541
CATEGORIES=	net dns
MASTER_SITES=	http://opensource.apple.com/tarballs/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bonjour (zero-configuration networking) by Apple

LICENSE=	AL2 BSD
LICENSE_COMB=	dual

CONFLICTS=	avahi-libdns-[0-9]*

BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
MAKE_ARGS=	LOCALBASE=${PREFIX} MANPATH=${MANPREFIX}/man os=freebsd
USES=		bison gmake
USE_LDCONFIG=	yes
USE_RC_SUBR=	mdnsd mdnsresponder

EXTRA_BIN=	mDNSClientPosix mDNSIdentify mDNSNetMonitor mDNSProxyResponderPosix mDNSResponderPosix
EXTRA_MAN1=	dns-sd.1
EXTRA_MAN8=	dnsextd.8 mDNSResponderPosix.8
EXTRA_SBIN=	dnsextd

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
MAKE_ARGS+=	LD="${CC} -shared"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/	cc / s|cc|$${CC}|' ${WRKSRC}/Clients/Makefile
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|g; s|mDNSResponder.8|mDNSResponderPosix.8|g' ${WRKSRC}/mDNSPosix/Makefile
	@${REINPLACE_CMD} -e 's|\(#define IPV6_2292_PKTINFO \).*|\1IPV6_PKTINFO|; s|\(#define IPV6_2292_HOPLIMIT \).*|\1IPV6_HOPLIMIT|' ${WRKSRC}/mDNSPosix/mDNSUNP.h
	@${MV} ${WRKSRC}/mDNSShared/mDNSResponder.8 ${WRKSRC}/mDNSShared/mDNSResponderPosix.8

post-build:
	@${STRIP_CMD} ${WRKSRC}/Clients/build/dns-sd ${WRKSRC}/mDNSPosix/build/prod/mdnsd ${WRKSRC}/mDNSPosix/build/prod/libdns_sd.so

post-install:
	cd ${WRKSRC}/mDNSPosix/build/prod/ && ${INSTALL_PROGRAM} ${EXTRA_BIN} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/mDNSShared/ && ${INSTALL_MAN} ${EXTRA_MAN1} ${STAGEDIR}${PREFIX}/man/man1/
	cd ${WRKSRC}/mDNSShared/ && ${INSTALL_MAN} ${EXTRA_MAN8} ${STAGEDIR}${PREFIX}/man/man8/
	cd ${WRKSRC}/mDNSPosix/build/prod/ && ${INSTALL_PROGRAM} ${EXTRA_SBIN} ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.post.mk>
