# New ports collection makefile for: linbot
# Date created:        19 September 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	linbot
PORTVERSION= 	0.9
CATEGORIES=	www python
MASTER_SITES=	http://starship.skyport.net/crew/marduk/linbot/download/

MAINTAINER=	billf@FreeBSD.org

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yeah

MAN1=		linbot.1

do-install:
	${MKDIR} ${PREFIX}/share/linbot
	${CP} ${WRKSRC}/*.py ${PREFIX}/share/linbot
	${CP} ${WRKSRC}/*.css ${PREFIX}/share/linbot
	${CP} ${WRKSRC}/contrib/*.1 ${PREFIX}/man/man1
	${LN} -sf ${PREFIX}/share/linbot/linbot.py ${PREFIX}/bin/linbot

.include <bsd.port.mk>
