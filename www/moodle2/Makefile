# New ports collection makefile for:	moodle
# Date created:				30 September 2005
# Whom:					Javier Martin Rueda <jmrueda@diatel.upm.es>
#
# $FreeBSD$
#

PORTNAME=	moodle
PORTVERSION=	2.1.2
CATEGORIES=	www
MASTER_SITES=	http://download.moodle.org/stable21/ \
		http://download2.moodle.org/stable21/ \
		http://download3.moodle.org/stable21/ \
		http://download4.moodle.org/stable21/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Course management system based on social constructionism

BUILD_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/intl.so:${PORTSDIR}/devel/pecl-intl
RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/intl.so:${PORTSDIR}/devel/pecl-intl

CONFLICTS=	moodle-1.*.* moodle-2.0.*
LATEST_LINK=	moodle21

USE_PHP=	session gd pcre mbstring iconv tokenizer curl xml xmlrpc ctype \
		soap openssl simplexml spl dom json zip zlib
WRKSRC=		${WRKDIR}/moodle

OPTIONS=	MYSQL   "Add support for a MySQL database server" On \
		PGSQL   "Add support for a PostgreSQL database server" Off \
		MSSQL   "Add support for a MS SQL Server" Off \
		LDAP    "Add LDAP authentication functionality" Off \
		MIMETEX "Add mimeTeX filter functionality" Off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysqli
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_MSSQL)
USE_PHP+=	mssql
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_MIMETEX)
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
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MOODLEDIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MOODLEDIR}?g" >> ${PLIST}
	@${ECHO} @dirrm ${MOODLEDATADIR} >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${MOODLEDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MOODLEDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MOODLEDIR}' \
		>> ${TMPPLIST}
	${CHMOD} -R 755 ${PREFIX}/${MOODLEDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${PREFIX}/${MOODLEDIR}' >> ${TMPPLIST}

	@${INSTALL} -d ${PREFIX}/${MOODLEDATADIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MOODLEDATADIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MOODLEDATADIR}' \
		>> ${TMPPLIST}
	${CHMOD} 755 ${PREFIX}/${MOODLEDATADIR}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/${MOODLEDATADIR}' >> ${TMPPLIST}
.if !defined(WITHOUT_MIMETEX)
	${LN} -sf ${PREFIX}/www/mimetex/cgi-bin/mimetex.cgi ${PREFIX}/${MOODLEDIR}/filter/tex/mimetex.freebsd
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
