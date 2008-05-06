# New ports collection makefile for:	habari
# Date created:				Mar 30 2008
# Whom:					ayunyan <ayunyan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	habari
PORTVERSION=	0.4.1
CATEGORIES=	www
MASTER_SITES=	http://habariproject.org/dist/

MAINTAINER=	ayunyan@gmail.com
COMMENT=	Next-generation free software blogging platform

USE_ZIP=	yes
USE_PHP=	pdo pdo_mysql pcre simplexml
NO_BUILD=	yes
WANT_PHP_MOD=	yes

do-install:
	@${MKDIR} ${WWWDIR}
	@${CHMOD} 755 ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})
	@${TOUCH} ${WWWDIR}/.htaccess
	@${CHOWN} ${WWWOWN} ${WWWDIR}/.htaccess

.include <bsd.port.mk>
