# Created by: Alfred Perlstein <alfred@freebsd.org>
# $FreeBSD$

PORTNAME=	mDNSResponder
PORTVERSION=	379.38.1
CATEGORIES=	net dns
MASTER_SITES=	http://opensource.apple.com/tarballs/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bonjour (zero-configuration networking) by Apple

LICENSE=	AL2 BSD
LICENSE_COMB=	dual

CONFLICTS=	avahi-libdns-[0-9]*

BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
MAKE_ARGS=	os=freebsd LOCALBASE=${PREFIX} MANPATH=${MANPREFIX}/man
USES=		bison gmake
USE_LDCONFIG=	yes
USE_RC_SUBR=	mdnsd

EXTRA_BIN=	bin/mDNSClientPosix bin/mDNSIdentify bin/mDNSNetMonitor \
		bin/mDNSProxyResponderPosix bin/mDNSResponderPosix
EXTRA_MAN8=	dnsextd.8 mDNSResponderPosix.8
EXTRA_SBIN=	sbin/dnsextd
MAN8=		mdnsd.8 ${EXTRA_MAN8}
PLIST_FILES=	bin/dns-sd ${EXTRA_BIN} \
		include/dns_sd.h \
		lib/libdns_sd.so lib/libdns_sd.so.1 \
		sbin/mdnsd ${EXTRA_SBIN}

post-patch:
	@${REINPLACE_CMD} -e '/	cc / s|cc|$${CC}|' ${WRKSRC}/Clients/Makefile
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|g; s|mDNSResponder.8|mDNSResponderPosix.8|g' ${WRKSRC}/mDNSPosix/Makefile
	@${MV} ${WRKSRC}/mDNSShared/mDNSResponder.8 ${WRKSRC}/mDNSShared/mDNSResponderPosix.8

post-install:
	cd ${WRKSRC}/mDNSPosix/build/prod/ && \
		${INSTALL_PROGRAM} ${EXTRA_BIN:T} ${PREFIX}/bin/ && \
		${INSTALL_PROGRAM} ${EXTRA_SBIN:T} ${PREFIX}/sbin/
	cd ${WRKSRC}/mDNSShared/ && \
		${INSTALL_MAN} ${EXTRA_MAN8} ${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
