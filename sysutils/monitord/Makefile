# New ports collection makefile for:	monitord
# Date created:				5 June 2000
# Whom:					walt
#
# $FreeBSD$
#

PORTNAME=	monitord
PORTVERSION=	0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.erudition.net/pub/monitord/

MAINTAINER=	walt@erudition.net

MAN8=		monitord.8

post-install:
	@${CP} ${WRKSRC}/monitord.conf ${PREFIX}/etc/monitord.conf.dist

.include <bsd.port.mk>
