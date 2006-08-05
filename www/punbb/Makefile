# New ports collection makefile for:	punbb
# Date created:		2006-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	punbb
PORTVERSION=	1.2.12
CATEGORIES=	www
MASTER_SITES=	http://www.punbb.org/download/ \
		http://punbb.pxtek.com/ \
		http://punbb.nhost.co.uk/ \
		http://mirror.ordo.dk/punbb.org/ \
		http://punbb.mirrors.typhon.net/ \
		http://punbb.4any.org/

MAINTAINER=	gslin@gslin.org
COMMENT=	A fast and lightweight PHP-powered discussion board

NO_BUILD=	yes
USE_PHP=	yes
PUNBBDIR?=	${PREFIX}/www/punbb

do-install:
	${MKDIR} ${PUNBBDIR}
	${CP} -R ${WRKSRC}/* ${PUNBBDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PUNBBDIR}

.include <bsd.port.mk>
