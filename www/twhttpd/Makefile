# New ports collection makefile for:	twhttpd-1.0
# Date created: 	25 Sep 2002
# Whom:			Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	twhttpd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.geocities.com/samngms/twhttpd/download/
DISTNAME=	twhttpd-${PORTVERSION}

MAINTAINER=	opr@bsdaemon.be
COMMENT=	Secure HTTP Proxy

GNU_CONFIGURE=  yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes

do-install:
	@${INSTALL_PROGRAM} -o root -g wheel -m 0755 ${WRKSRC}/twhttpd ${PREFIX}/sbin/twhttpd
	@${INSTALL} -o root -g wheel -m 0755 ${WRKSRC}/rm_cache ${PREFIX}/sbin/rm_cache
	@${INSTALL} -o root -g wheel -m 0700 ${WRKSRC}/twhttpd.cfg ${PREFIX}/etc/twhttpd.cfg.sample

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
