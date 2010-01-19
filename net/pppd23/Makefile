# New ports collection makefile for:   pppd 2.3.11
# Date created:        10 April 2004
# Whom:                netch@netch.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	pppd
PORTVERSION=	2.3.11
CATEGORIES=	net
MASTER_SITES=	http://samba.anu.edu.au/ftp/ppp/
DISTNAME=	ppp-${PORTVERSION}

MAINTAINER=	netch@netch.kiev.ua
COMMENT=	PPP daemon which uses ppp line discipline

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-no-logf

GNU_CONFIGURE=	yes
MAN8=		pppd.8 pppstats.8 chat.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800045
IGNORE=		depends on PPPDISC, which is no longer available
.endif

.include <bsd.port.post.mk>
