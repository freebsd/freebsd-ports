# New ports collection makefile for:	phpMyID
# Date created:		2006-12-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	phpMyID
PORTVERSION=	0.9
CATEGORIES=	security www
MASTER_SITES=	http://siege.org/projects/phpMyID/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dan@langille.org
COMMENT=	A single user Identity Provider for the OpenID framework

DEPRECATED=	Development has ceased.
EXPIRATION_DATE=	 2011-01-01

NO_BUILD=	yes
USE_PHP=	session

OPTIONS=	BCMATH "Big math using bcmath lib (recommended by author)" on

do-install:
	${MKDIR} ${PREFIX}/www/${PORTNAME}
	${CP} -R ${WRKSRC}/ ${PREFIX}/www/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_BCMATH)
USE_PHP+=	bcmath
.endif

.include <bsd.port.post.mk>
