# New ports collection makefile for:	squidpurge
# Date created:		Fri Oct 19 23:00:00 WST 2001
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	squidpurge
PORTVERSION=	1.17
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/ \
		http://www.squid-cache.org/contrib/
DISTNAME=	purge-20040201-src

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Powerful object purging utility for the Squid web proxy cache

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/purge

PLIST_FILES=	sbin/purge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/purge ${PREFIX}/sbin

.include <bsd.port.mk>
