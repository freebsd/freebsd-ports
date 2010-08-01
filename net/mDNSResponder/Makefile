# ex:ts=8
# Ports collection makefile for:  mDNSResponder
# Date created:			  Tues Mar 2, 2004
# Whom:				  Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mDNSResponder
PORTVERSION=	214.3
CATEGORIES=	net dns
MASTER_SITES=	http://opensource.apple.com/tarballs/mDNSResponder/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Apple's mDNSResponder

BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
MAKE_ARGS+=	os=freebsd LOCALBASE=${PREFIX} MANPATH=${MANPREFIX}/man
MAKE_JOBS_UNSAFE=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	mdnsd
EXTRA_PROGS_BIN=mDNSClientPosix mDNSIdentify mDNSNetMonitor \
		mDNSProxyResponderPosix mDNSResponderPosix
EXTRA_PROGS_SBIN=dnsextd

EXTRAMAN8=	dnsextd.8 mDNSResponderPosix.8
MAN8=		mdnsd.8 ${EXTRAMAN8}

CONFLICTS=	avahi-libdns-[0-9]*

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${MV} ${WRKSRC}/mDNSShared/mDNSResponder.8 \
		${WRKSRC}/mDNSShared/mDNSResponderPosix.8

pre-build:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|mDNSResponder.8|mDNSResponderPosix.8|g' \
		${WRKSRC}/mDNSPosix/Makefile

post-install:
	@cd ${INSTALL_WRKSRC}/build/prod && \
		${INSTALL_PROGRAM} ${EXTRA_PROGS_BIN} ${PREFIX}/bin && \
		${INSTALL_PROGRAM} ${EXTRA_PROGS_SBIN} ${PREFIX}/sbin
.for page in ${EXTRAMAN8}
	@${INSTALL_MAN} ${WRKSRC}/mDNSShared/${page} ${MAN8PREFIX}/man/man8/
.endfor

.include <bsd.port.post.mk>
