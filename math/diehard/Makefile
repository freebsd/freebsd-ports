# New ports collection makefile for:	diehard
# Date created:	   04 Jule 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	diehard
PORTVERSION=	0.1
CATEGORIES=	math
MASTER_SITES=	http://www.cs.hku.hk/~diehard/cdrom/ \
		http://stat.fsu.edu/pub/diehard/
DISTNAME=	die.c

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Marsaglia's Diehard Battery of Tests of Randomness

ALL_TARGET=	diehard
USE_REINPLACE=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_SUB=	DOCSDIR="share/doc/${PORTNAME}" DATADIR="share/${PORTNAME}"

DOCSLIST=	NOTES readme

post-patch:
	@${REINPLACE_CMD} -e 's|operm5\.cov|${DATADIR}/operm5.cov|g;' \
		${WRKSRC}/cdoperm5.c
	@${REINPLACE_CMD} -e 's|CC=gcc||g;' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diehard ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/operm5.cov ${DATADIR}

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S!^!${WRKSRC}/!} ${DOCSDIR}
.endif

.include <bsd.port.mk>
