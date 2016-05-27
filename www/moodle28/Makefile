# Created by: Javier Martin Rueda <jmrueda@diatel.upm.es>
# $FreeBSD$

PORTNAME=	moodle
PORTVERSION=	2.8.12
CATEGORIES=	www
MASTER_SITES=	SF/moodle/Moodle/stable28/
PKGNAMESUFFIX=	${PKGORIGIN:T:S/moodle//}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Course management system based on social constructionism

LICENSE=	GPLv3

CONFLICTS=	moodle30-3.0.[0-9]* moodle29-2.9.[0-9]* moodle31-3.1

DEPRECATED=	EOL upstream
EXPIRATION_DATE=	2016-08-24

USES=		cpe tar:tgz
USE_PHP=	session gd pcre mbstring iconv tokenizer curl xml xmlrpc ctype \
		soap openssl simplexml spl dom json zip zlib hash opcache intl
WRKSRC=		${WRKDIR}/moodle

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL MSSQL
OPTIONS_DEFINE=		LDAP MIMETEX
OPTIONS_DEFAULT=	MYSQL
MIMETEX_DESC=		mimeTeX filter functionality support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MMSSQL}
USE_PHP+=	mssql
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MMIMETEX}
RUN_DEPENDS+=	${LOCALBASE}/www/mimetex/cgi-bin/mimetex.cgi:www/mimetex
.endif

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MOODLEDIR=${MOODLEDIR} \
		MOODLEDATADIR=${MOODLEDATADIR}

MOODLEDIR?=	www/moodle
MOODLEDATADIR?=	moodledata

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MOODLEDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${MOODLEDIR}?g" >> ${PLIST}

	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${ECHO} @dir ${MOODLEDATADIR} >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MOODLEDIR}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${MOODLEDATADIR}
.if ${PORT_OPTIONS:MMIMETEX}
	${LN} -sf ${PREFIX}/www/mimetex/cgi-bin/mimetex.cgi \
		${STAGEDIR}${PREFIX}/${MOODLEDIR}/filter/tex/mimetex.freebsd
.endif

.include <bsd.port.mk>
