# ex:ts=8
# Ports collection makefile for:  mDNSResponder
# Date created:			  Tues Mar 2, 2004
# Whom:				  Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mDNSResponder
PORTVERSION=	107.1
CATEGORIES=	net dns
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@freebsd.org
COMMENT=	"Apple's mDNSResponder"

INSTALLS_SHLIB=	YES

USE_GMAKE=	YES
USE_REINPLACE=	YES
USE_RC_SUBR=	mdnsd.sh
MAKE_ARGS+=	os=freebsd LOCALBASE=${PREFIX} MANPATH=${MANPREFIX}/man
BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
EXTRA_PROGS_BIN=mDNSClientPosix \
		mDNSIdentify \
		mDNSNetMonitor \
		mDNSProxyResponderPosix \
		mDNSResponderPosix
EXTRA_PROGS_SBIN=dnsextd

EXTRAMAN8=	dnsextd.8 mDNSResponder.8

MAN8=		mdnsd.8 ${EXTRAMAN8}

pre-build:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/mDNSPosix/Makefile

post-install:
	cd ${INSTALL_WRKSRC}/build/prod && \
		${INSTALL_PROGRAM} ${EXTRA_PROGS_BIN} ${PREFIX}/bin && \
		${INSTALL_PROGRAM} ${EXTRA_PROGS_SBIN} ${PREFIX}/sbin
.	for section in 1 2 3 4 5 6 7 8
.		for page in ${EXTRAMAN${section}}
			${INSTALL_MAN} ${WRKSRC}/mDNSShared/${page} ${MAN${section}PREFIX}/man/man${page:E}/
.		endfor
.	endfor

.include <bsd.port.mk>
