# New ports collection makefile for:	textpattern
# Date created:		30 Nov 2005
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	textpattern
PORTVERSION=	4.0.3
CATEGORIES=	www
MASTER_SITES=	http://www.textpattern.com/dload/

MAINTAINER=	babak@farrokhi.net
COMMENT=	A free, flexible, elegant, easy-to-use content management system

NO_BUILD=	YES
WANT_PHP_WEB=	YES
WWWOWN?=	www
WWWGRP?=	www
TEXTPATTERN?=	www/data-dist/${PORTNAME}
PLIST_SUB+=	TEXTPATTERN=${TEXTPATTERN}
USE_PHP=	mbstring xml

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off

.if defined(PHP_VER) && ${PHP_VER} == 5
OPTIONS+=	SQLITE "Use SQLite backend" off
.endif

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

# Options that default to on:
.if !defined(WITHOUT_MYSQL) || defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

do-install:
	-${MKDIR} ${PREFIX}/${TEXTPATTERN}
	@(cd ${WRKSRC} && ${CP} -R * ${PREFIX}/${TEXTPATTERN}/ )

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
