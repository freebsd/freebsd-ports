# New ports collection makefile for:	phpscheduleit
# Date created:				4 Januar 2011
# Whom:					jamrich.majo@gmail.com
#
# $FreeBSD$
#

PORTNAME=	phpscheduleit
PORTVERSION=	1.2.12
CATEGORIES=	www
MASTER_SITES=	SF/phpscheduleit/1.%20phpScheduleIt/${PORTVERSION}
DISTNAME=	phpScheduleIt_${PORTVERSION}

MAINTAINER=	jamrich.majo@gmail.com
COMMENT=	A web-based resource scheduling and management system

RUN_DEPENDS+=	php:${PORTSDIR}/lang/php5 \
		${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB

PEARDIR=	${PREFIX}/share/pear
USE_PHP+=	mysql
USE_MYSQL=	yes
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=      pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

OPTIONS=	POSTGRE "Use PostgreSQL Database" off \
		APACHE "Use Apache webserver" on \
		LIGHTTPD "Use Lighttpd webserver" off

.include <bsd.port.options.mk>

.if defined(WITH_POSTGRE)
USE_PHP+=	pgsql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif
.if defined(WITH_APACHE)
USE_APACHE=	22
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
