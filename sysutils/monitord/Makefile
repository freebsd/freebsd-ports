# New ports collection makefile for:	monitord
# Date created:				5 June 2000
# Whom:					walt
#
# $FreeBSD$
#

PORTNAME=	monitord
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.erudition.net/pub/monitord/

MAINTAINER=	walt@erudition.net
COMMENT=	Service that restarts other standalone services

MAN8=		monitord.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

post-install:
	@${CP} ${WRKSRC}/monitord.conf.sample ${PREFIX}/etc/monitord.conf.sample

.include <bsd.port.post.mk>
