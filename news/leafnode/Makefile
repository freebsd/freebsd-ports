# New ports collection makefile for:	leafnode
# Version required:	1.0.1
# Date created:		10 April 1996
# Whom:			Patrick Yu <pyu@rogidi.com>
#			Brian Somers <brian@awfulhak.org>
#
# $Id: Makefile,v 1.1.1.1 1997/06/27 23:00:49 brian Exp $
#

DISTNAME=	leafnode-1.0.1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/news/readers
EXTRACT_SUFX=	.ELF.tgz

MAINTAINER=	brian@awfulhak.org

MAN8=		fetch.8 leafnode.8 texpire.8

post-install:
	strip ${PREFIX}/sbin/fetch ${PREFIX}/sbin/leafnode ${PREFIX}/sbin/texpire

.include <bsd.port.mk>
