# New ports collection makefile for:	transproxy
# Date created:			Fri Mar 27 21:24:13 WST 1998
# Whom:				Peter Wemm <peter@netplex.com.au>
#
# $FreeBSD$
#

PORTNAME=	transproxy
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nlc.net.au/pub/unix/transproxy/
EXTRACT_SUFX=	.tgz

MAINTAINER=	peter@FreeBSD.org

MAN8=		tproxy.8

.include <bsd.port.pre.mk>

# Requires FreeBSD-3.0 or higher because of a feature it uses to ignore
# the death of child processes. Also later versions of FreeBSD have the
# ipfw fwd rule, and IPFILTER ipnat command, which is needed for this
# sort of program anyway.
.if ${OSVERSION} < 300000
BROKEN=		"transproxy requires SA_NOCLDWAIT, available in 3.x or later"
.endif

.include <bsd.port.post.mk>
