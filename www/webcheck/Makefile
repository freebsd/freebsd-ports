# New ports collection makefile for: linbot
# Date created:        19 September 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	linbot
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/misc
EXTRACT_SUFX=	.tgz

MAINTAINER=	billf@FreeBSD.org

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yeah

do-install:
	${MKDIR} ${PREFIX}/share/linbot
	${CP} ${WRKSRC}/*.py ${PREFIX}/share/linbot
	${CP} ${WRKSRC}/*.css ${PREFIX}/share/linbot
.for d in plugins schemes
	${MKDIR} ${PREFIX}/share/linbot/${d}
	${CP} ${WRKSRC}/${d}/*.py ${PREFIX}/share/linbot/${d}
.endfor
	${LN} -sf ${PREFIX}/share/linbot/linbot.py ${PREFIX}/bin/linbot

.include <bsd.port.mk>
