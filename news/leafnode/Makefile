# New ports collection makefile for:	leafnode
# Version required:	1.9.7
# Date created:		10 April 1996
# Whom:			Brian Somers <brian@Awfulhak.org>
#
# $FreeBSD$
#

DISTNAME=	leafnode-1.9.11
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.Awfulhak.org/leafnode/
MASTER_SITE_SUBDIR=	system/news/transport

MAINTAINER=	brian@Awfulhak.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
MAKE_ARGS=	LOCKFILE=/var/spool/lock/news/fetchnews.lck \
		LIBDIR=${PREFIX}/lib/leafnode
MAN1=		newsq.1
MAN8=		fetchnews.8 applyfilter.8 leafnode.8 texpire.8 checkgroups.8

.include <bsd.port.mk>
