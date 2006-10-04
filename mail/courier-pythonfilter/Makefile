# New ports collection makefile for:	courier-pythonfilter
# Date created:				Jun 19, 2006
# Whom:					Milan Obuch
#
# $FreeBSD$
#

PORTNAME=	courier-pythonfilter
PORTVERSION=	0.9
CATEGORIES=	mail python
MASTER_SITES=	http://phantom.dragonsdawn.net/~gordon/courier-patches/courier-pythonfilter/

MAINTAINER=	bsd@dino.sk
COMMENT=	Framework for courier filter development in python

BUILD_DEPENDS=	courier-config:${PORTSDIR}/mail/courier

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAILOWN=	courier
MAILGRP=	courier
MAILUID=	465
MAILGID=	465

LOCALSTATEDIR=	/var/spool/courier
SCRIPTSDIR=	${PREFIX}/libexec/filters

post-extract:
	${MV} ${WRKSRC}/filters/whitelist-auth.py ${WRKSRC}/filters/whitelist_auth.py

post-install:
	${MKDIR} ${LOCALSTATEDIR}/pythonfilter
	${CHOWN} ${MAILOWN}:${MAILGRP} ${LOCALSTATEDIR}/pythonfilter

.include <bsd.port.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS} --install-scripts=${SCRIPTSDIR}
