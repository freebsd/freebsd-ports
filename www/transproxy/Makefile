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
EXTRACT_SUFX=	.tgz

MAINTAINER=	peter@FreeBSD.org

ALL_TARGET=	tproxy

.include <bsd.port.pre.mk>

# This has only been tested with -current, although it might work if you
# can get the ipfilter package to build on a 2.2.x system. YMMV.
# ftp://cheops.anu.edu.au/pub/net/firewall/ip-filter/
.if ${OSVERSION} < 300000
BROKEN=		"transproxy requires ipfilter, available in 3.0 or later"
.endif

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${WRKSRC}/tproxy ${PREFIX}/sbin

.include <bsd.port.post.mk>
