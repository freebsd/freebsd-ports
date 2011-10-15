# Ports collection makefile for:  mDNSResponder
# Date created:		Tues Mar 2, 2004
# Whom:			Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mDNSResponder
PORTVERSION=	320.10
CATEGORIES=	net dns
MASTER_SITES=	http://opensource.apple.com/tarballs/mDNSResponder/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Apple's mDNSResponder

LICENSE=	ASL BSD
LICENSE_COMB=	dual

CONFLICTS=	avahi-libdns-[0-9]*

BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
MAKE_ARGS=	os=freebsd LOCALBASE=${PREFIX} MANPATH=${MANPREFIX}/man
USE_BISON=	build
USE_GMAKE=	yes
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e '/	cc / s|cc|$${CC}|' ${WRKSRC}/Clients/Makefile
	@${MV} ${WRKSRC}/mDNSShared/mDNSResponder.8 \
		${WRKSRC}/mDNSShared/mDNSResponderPosix.8

pre-build:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|mDNSResponder.8|mDNSResponderPosix.8|g' \
		${WRKSRC}/mDNSPosix/Makefile

post-install:
	@cd ${INSTALL_WRKSRC}/build/prod && \
		${INSTALL_PROGRAM} ${EXTRA_BIN:T} ${PREFIX}/bin/ && \
		${INSTALL_PROGRAM} ${EXTRA_SBIN:T} ${PREFIX}/sbin/
	@cd ${WRKSRC}/mDNSShared/ && \
		${INSTALL_MAN} ${EXTRA_MAN8} ${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
