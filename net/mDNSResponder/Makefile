# ex:ts=8
# Ports collection makefile for:  mDNSResponder
# Date created:			  Tues Mar 2, 2004
# Whom:				  Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mDNSResponder
PORTVERSION=	62
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	alfred@freebsd.org
COMMENT=	"Apple's mDNSResponder"

INSTALLS_SHLIB=	YES

USE_GMAKE=	YES
MAKE_ARGS+=	os=freebsd
BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix
EXTRA_PROGS=	mDNSClientPosix \
		mDNSIdentify \
		mDNSNetMonitor \
		mDNSProxyResponderPosix \
		mDNSResponderPosix

post-install:
	cd ${INSTALL_WRKSRC}/build/prod && \
	    ${INSTALL_PROGRAM} ${EXTRA_PROGS} ${PREFIX}/bin

.include <bsd.port.mk>
