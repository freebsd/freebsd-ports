# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	diehard
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://stat.fsu.edu/pub/diehard/
DISTNAME=	die-c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Marsaglia's Diehard Battery of Tests of Randomness

BROKEN=		unfetchable

LICENSE=	NONE

ALL_TARGET=	diehard
WRKSRC=		${WRKDIR}/die.c
PLIST_SUB=	DOCSDIR="share/doc/${PORTNAME}" DATADIR="share/${PORTNAME}"

DOCSLIST=	NOTES readme

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|operm5\.cov|${DATADIR}/operm5.cov|g;' \
		${WRKSRC}/cdoperm5.c
	@${REINPLACE_CMD} -e 's|CC=gcc||g;' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diehard ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/operm5.cov ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S!^!${WRKSRC}/!} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
