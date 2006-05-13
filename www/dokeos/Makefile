# New ports collection makefile for:	dokeos
# Date created:				21 January 2006
# Whom:					Filipe Rocha <filiperocha@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dokeos
PORTVERSION=	1.6.4
CATEGORIES=	www
MASTER_SITES=	http://www.dokeos.com/download/

MAINTAINER=	filiperocha@gmail.com
COMMENT=	Dokeos is an elearning and course management web application

USE_PHP=	mysql session gd pcre zlib
DIST_SUBDIR=	${PORTNAME}

NO_BUILD=	yes

WANT_PHP_WEB=	YES

DOKEOSDIR?=	www/dokeos

OPTIONS=	LDAP "Use LDAP" off

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

ALL_OPTIONS=	LDAP

SEL_OPTIONS=	yes
.for opt in ${ALL_OPTIONS}
.       if defined(WITH_${opt}) && !defined(WITHOUT_${opt})
SEL_OPTIONS+=${opt:L}
.       endif
.endfor

USE_PHP+=	${SEL_OPTIONS}

do-install:
	@${INSTALL_DATA} -d ${PREFIX}/${DOKEOSDIR}
	@${CP} -Rn ${WRKSRC}/* ${PREFIX}/${DOKEOSDIR}
	@${FIND} ${PREFIX}/${DOKEOSDIR} -type d -exec ${CHMOD} +x {} \;
	@${FIND} ${PREFIX}/${DOKEOSDIR}/claroline/inc/conf -type d -exec ${CHMOD} -R +rwx {} \;
	@${FIND} ${PREFIX}/${DOKEOSDIR}/claroline/garbage -type d -exec ${CHMOD} -R +rwx {} \;
	@${FIND} ${PREFIX}/${DOKEOSDIR}/claroline/upload -type d -exec ${CHMOD} -R +rwx {} \;
	@${FIND} ${PREFIX}/${DOKEOSDIR}/archive -type d -exec ${CHMOD} -R +rwx {} \;
	@${FIND} ${PREFIX}/${DOKEOSDIR}/courses -type d -exec ${CHMOD} -R +rwx {} \;
	@${FIND} ${PREFIX}/${DOKEOSDIR}/home -type d -exec ${CHMOD} -R +rwx {} \;

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKEOSDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
