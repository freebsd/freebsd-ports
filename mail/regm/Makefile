# New ports collection makefile for:	regm
# Date created:				21 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	regm
PORTVERSION=	1.0
CATEGORIES=	mail python
MASTER_SITES=	http://perso.linuxfr.org/jdumont/regm/

MAINTAINER=	petef@databits.net

NO_BUILD=	yes
USE_PYTHON=	yes

post-patch:
	@${PERL} -pi -e 's|^#!/usr/bin/env python|#!${PYTHON_CMD}|' \
		${WRKSRC}/regm.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/regm.py ${PREFIX}/bin/regm

.include <bsd.port.mk>
