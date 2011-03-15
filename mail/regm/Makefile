# New ports collection makefile for:	regm
# Date created:				21 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	regm
PORTVERSION=	1.0
CATEGORIES=	mail python
MASTER_SITES=	http://hamete.org/regm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract messages from a mailbox using regular expressions

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	bin/regm
NO_BUILD=	yes
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/env python|#!${PYTHON_CMD}|' \
		${WRKSRC}/regm.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/regm.py ${PREFIX}/bin/regm

.include <bsd.port.mk>
