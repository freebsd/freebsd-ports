# New ports collection makefile for:	diffstat
# Version required:	1.27
# Date created:		Oct 23, 1999
# Whom:			Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

DISTNAME=	diffstat-1.27
CATEGORIES=	textproc devel
MASTER_SITES=	ftp://ftp.clark.net/pub/dickey/diffstat/ \
		http://www.clark.net/pub/dickey/diffstat/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@jpj.net

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
#USE_AUTOCONF=	yes

MAN1=		diffstat.1

post-install:
	strip -s ${PREFIX}/bin/diffstat

.include <bsd.port.mk>
