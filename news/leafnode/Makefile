# New ports collection makefile for:	leafnode
# Version required:	1.0.2
# Date created:		10 April 1996
# Whom:			Brian Somers <brian@awfulhak.org>
#
# $Id: Makefile,v 1.2 1997/06/29 09:12:59 obrien Exp $
#

DISTNAME=	leafnode-1.0.2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/news/readers
EXTRACT_SUFX=	.src.elf.tgz

MAINTAINER=	brian@awfulhak.org

MAN8=		fetch.8 leafnode.8 texpire.8

post-install:
	strip ${PREFIX}/sbin/fetch ${PREFIX}/sbin/leafnode ${PREFIX}/sbin/texpire

.include <bsd.port.mk>
