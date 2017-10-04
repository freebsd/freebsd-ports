# Created by: Javier Martin Rueda <jmrueda@diatel.upm.es>
# $FreeBSD$

PORTNAME=	moodle
PORTVERSION=	3.1.8
CATEGORIES=	www
MASTER_SITES=	SF/moodle/Moodle/stable31/
PKGNAMESUFFIX=	${PKGORIGIN:T:S/moodle//}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Course management system based on social constructionism

LICENSE=	GPLv3

CONFLICTS=	moodle30-3.0.[0-9]* moodle32-3.2.[0-9]* moodle33-3.3.[0-9]*

USES=		cpe php tar:tgz
USE_PHP=	ctype curl dom gd hash iconv intl json mbstring opcache \
		openssl pcre session simplexml soap spl tokenizer xml \
		xmlreader xmlrpc zip zlib
WRKSRC=		${WRKDIR}/moodle

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL MSSQL
OPTIONS_DEFINE=		LDAP MIMETEX
OPTIONS_DEFAULT=	MYSQL
MIMETEX_DESC=		mimeTeX filter functionality support

MYSQL_USES=	mysql:client
MYSQL_USE=	php=mysqli
PGSQL_USE=	php=pgsql
MSSQL_USE=	php=mssql
LDAP_USE=	php=ldap
MIMETEX_RUN_DEPENDS=	${LOCALBASE}/www/mimetex/cgi-bin/mimetex.cgi:www/mimetex

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MOODLEDIR=${MOODLEDIR} \
		MOODLEDATADIR=${MOODLEDATADIR}

MOODLEDIR?=	www/moodle
MOODLEDATADIR?=	moodledata

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${ECHO} @dir ${MOODLEDATADIR} >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

#  Here for safety I do not set moodle diretory 0755 permission
#  It require user write config.php manually then.
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MOODLEDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${MOODLEDIR}?g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MOODLEDIR}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${MOODLEDATADIR}

do-install-MIMETEX-on:
	${LN} -sf ${PREFIX}/www/mimetex/cgi-bin/mimetex.cgi \
		${STAGEDIR}${PREFIX}/${MOODLEDIR}/filter/tex/mimetex.freebsd

.include <bsd.port.mk>
