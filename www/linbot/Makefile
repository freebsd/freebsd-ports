# New ports collection makefile for: linbot
# Version required:    0.8
# Date created:        19 September 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.1.1.1 1998/09/21 05:42:14 jkoshy Exp $
#

DISTNAME=	linbot-0.9
CATEGORIES=	www
MASTER_SITES=	http://starship.skyport.net/crew/marduk/linbot/

MAINTAINER=	billf@chc-chimes.com

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
