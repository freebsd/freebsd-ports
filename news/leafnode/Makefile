# New ports collection makefile for:	leafnode
# Version required:	1.9.2
# Date created:		10 April 1996
# Whom:			Brian Somers <brian@Awfulhak.org>
#
# $Id: Makefile,v 1.5 1999/03/22 01:25:41 brian Exp $
#

DISTNAME=	leafnode-1.9.2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.Awfulhak.org/leafnode/
MASTER_SITE_SUBDIR=	system/news/transport

MAINTAINER=	brian@Awfulhak.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet --prefix=${PREFIX}
MAKE_ARGS=	LOCKFILE=/var/spool/lock/news/fetch.lck \
		LIBDIR=${PREFIX}/lib/leafnode
MAN1=		newsq.1
MAN8=		fetch.8 applyfilter.8 leafnode.8 texpire.8 checkgroups.8
MLINKS+=	fetch.8 fetch-news.8

post-install:
	/bin/ln -sf fetch ${PREFIX}/sbin/fetch-news

.include <bsd.port.mk>
