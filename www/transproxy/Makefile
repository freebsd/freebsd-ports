# New ports collection makefile for:	transproxy
# Version required:		0.3
# Date created:			Fri Mar 27 21:24:13 WST 1998
# Whom:				Peter Wemm <peter@netplex.com.au>
#
# $FreeBSD$
#

DISTNAME=	transproxy-0.3
CATEGORIES=	www net
MASTER_SITES=	ftp://ftp.nlc.net.au/pub/linux/www/
DISTFILES=	transproxy-0.3.tgz

MAINTAINER=	peter@FreeBSD.ORG

ALL_TARGET=	tproxy

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} < 300000
BROKEN=		"transproxy requires ipfilter, available in 3.0 or later"
.endif

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${WRKSRC}/tproxy ${PREFIX}/sbin

.include <bsd.port.mk>
