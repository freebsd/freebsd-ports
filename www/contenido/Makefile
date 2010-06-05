# New ports collection makefile for: contenido
# Date created:		25 Nov 2008
# Whom:			dirk.meyer
#
# $FreeBSD$
#

PORTNAME=	contenido
PORTVERSION=	4.8.12
CATEGORIES=	www
MASTER_SITES=	http://www.contenido.org/de/upload/versionen/
DISTNAME=	Contenido_${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Content Management System

LICENSE=	GPLv2

USE_ZIP=	YES
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	mysql pcre session gd xml spl
DEFAULT_PHP_VER?=	52
IGNORE_WITH_PHP=	5
.endif
NO_BUILD=	YES
WRKSRC=		${WRKDIR}

FIX_ME=	contenido/logs/ contenido/cronjobs/ contenido/temp/ \
	contenido/includes/ contenido/cache/ \
	cms/cache/ cms/css/ cms/js/ cms/logs/ cms/templates/ \
	cms/upload/ cms/config.php

.include <bsd.port.pre.mk>

do-install:
	-${MKDIR} ${WWWDIR}/contenido/cache ${WWWDIR}/cms/cache
	${CP} -Rp ${WRKSRC}/* ${WWWDIR}/
.for i in ${FIXME}
	${CHOWN} -R www ${WWWDIR}/${i}
.endfor

.include <bsd.port.post.mk>
