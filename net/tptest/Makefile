# New ports collection makefile for:   tptest
# Date created:        2002-12-30
# Whom:                Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	tptest
PORTVERSION=	3.1.0
CATEGORIES=	net benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Software suite for testing network throughput and Internet services

pre-build:
	@ cd ${WRKSRC}/apps/unix/client ;\
	${LN} -s ../../../os-dep/unix/*.[hc] ../../../engine/*.[hc] .

do-build:
	@ cd ${WRKSRC}/apps/unix/client; ${MAKE}
	@ cd ${WRKSRC}/apps/unix/server; ${MAKE}

do-install:
	@ ${INSTALL_PROGRAM} \
		${WRKSRC}/apps/unix/client/tptest \
		${WRKSRC}/apps/unix/server/tptestserver \
		${PREFIX}/bin

.include <bsd.port.mk>
