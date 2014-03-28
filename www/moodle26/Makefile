# Created by: Javier Martin Rueda <jmrueda@diatel.upm.es>
# $FreeBSD$

PORTNAME=	moodle
PORTVERSION=	2.6.2
CATEGORIES=	www
MASTER_SITES=	SF/moodle/Moodle/stable26/
PKGNAMESUFFIX=	${PKGORIGIN:T:S/moodle//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Course management system based on social constructionism

LICENSE=	GPLv3

BUILD_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/intl.so:${PORTSDIR}/devel/pecl-intl
RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/intl.so:${PORTSDIR}/devel/pecl-intl

CONFLICTS=	moodle-1.*.* moodle24-2.4.* moodle25-2.5.[0-9]*

USE_PHP=	session gd pcre mbstring iconv tokenizer curl xml xmlrpc ctype \
		soap openssl simplexml spl dom json zip zlib hash
WRKSRC=		${WRKDIR}/moodle

OPTIONS_DEFINE=	MYSQL PGSQL MSSQL LDAP MIMETEX
OPTIONS_DEFAULT=MYSQL
MSSQL_DESC=	MS SQL Server support
MIMETEX_DESC=	mimeTeX filter functionality support

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
RUN_DEPENDS+=	${LOCALBASE}/www/mimetex/cgi-bin/mimetex.cgi:${PORTSDIR}/www/mimetex
.endif

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
	@${ECHO_CMD} "@mode 755" >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MOODLEDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MOODLEDIR}?g" >> ${PLIST}
	@${ECHO} @dirrm ${MOODLEDATADIR} >> ${PLIST}
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
