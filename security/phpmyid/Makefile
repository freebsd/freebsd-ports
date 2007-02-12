# New ports collection makefile for:	phpMyID
# Date created:		2006-12-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	phpMyID
PORTVERSION=	0.5
CATEGORIES=	security www
MASTER_SITES=	http://siege.org/projects/phpMyID/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A single user Identity Provider for the OpenID framework

NO_BUILD=	yes
USE_PHP=	session

do-install:
	${MKDIR} ${PREFIX}/www/${PORTNAME}
	${CP} -R ${WRKSRC}/ ${PREFIX}/www/${PORTNAME}

.include <bsd.port.mk>
