# New ports collection makefile for:   tptest
# Date created:        2002-12-30
# Whom:                Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	tptest
PORTVERSION=	3.1.7
CATEGORIES=	net benchmarks
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTNAME}%203.1

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Software suite for testing network throughput and Internet services

PLIST_FILES=	bin/tptestclient bin/tptestserver

do-build:
	@cd ${WRKSRC}/apps/unix/client; ${MAKE}
	@cd ${WRKSRC}/apps/unix/server; ${MAKE}

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/apps/unix/client/tptestclient \
		${WRKSRC}/apps/unix/server/tptestserver \
		${PREFIX}/bin

.include <bsd.port.mk>
