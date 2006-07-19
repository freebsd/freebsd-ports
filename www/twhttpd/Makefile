# New ports collection makefile for:	twhttpd-1.0
# Date created: 	25 Sep 2002
# Whom:			Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	twhttpd
PORTVERSION=	1.01
CATEGORIES=	www
MASTER_SITES=	http://www.geocities.com/samngms/twhttpd/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure HTTP Proxy

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lmd"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's| md5\.o | |g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} -o root -g wheel -m 0755 ${WRKSRC}/twhttpd ${PREFIX}/sbin/twhttpd
	${INSTALL} -o root -g wheel -m 0755 ${WRKSRC}/rm_cache ${PREFIX}/sbin/rm_cache
	${INSTALL} -o root -g wheel -m 0700 ${WRKSRC}/twhttpd.cfg ${PREFIX}/etc/twhttpd.cfg.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
