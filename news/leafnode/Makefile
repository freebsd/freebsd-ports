# New ports collection makefile for:	leafnode
# Date created:		10 April 1996
# Whom:			Brian Somers <brian@Awfulhak.org>
#
# $FreeBSD$
#

PORTNAME=	leafnode
PORTVERSION=	1.9.17
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
MAN7=		pcre.7
MAN8=		fetchnews.8 applyfilter.8 leafnode.8 texpire.8 checkgroups.8

.include <bsd.port.mk>
