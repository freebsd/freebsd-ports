# New ports collection makefile for:	squid-purge
# Date created:				Fri Oct 19 23:00:00 WST 2001
# Whom:				Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	squidpurge
PORTVERSION=	1.17
CATEGORIES=	www
MASTER_SITES=	http://www.cache.dfn.de/DFN-Cache/Development/Purge/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
DISTNAME=	purge
EXTRACT_SUFX=	-20000921-src.tar.gz

MAINTAINER=	dean@odyssey.apana.org.au

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/purge ${PREFIX}/sbin

.include <bsd.port.mk>
