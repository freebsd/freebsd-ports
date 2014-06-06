# Created by: Javier Martin Rueda <jmrueda@diatel.upm.es>
# $FreeBSD$

PORTNAME=	moodle
PORTVERSION=	1.9.19
CATEGORIES=	www
MASTER_SITES=	SF/moodle/Moodle/stable19/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmrueda@diatel.upm.es
COMMENT=	Course management system based on social constructionism

CONFLICTS=	moodle-2.*.*

USE_PHP=	session gd pcre mbstring iconv tokenizer curl xml xmlrpc ctype
WRKSRC=		${WRKDIR}/moodle

OPTIONS_DEFINE=	MYSQL PGSQL MSSQL ZLIB NETWORK LDAP MIMETEX
OPTIONS_DEFAULT=	ZLIB
NETWORK_DESC=	Moodle Network functionality
MIMETEX_DESC=	mimeTeX filter functionality

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MPGSQL} && ! ${PORT_OPTIONS:MMSSQL}
pre-fetch:
	@${ECHO_MSG} "
	@${ECHO_MSG} "You didn't activate support for any database server!"
	@${ECHO_MSG} "
	@${ECHO_MSG} "If you want to reconsider, press Ctrl-C now to cancel"
	@${ECHO_MSG} "the installation and run 'make config'"
	@${ECHO_MSG} "
	@${ECHO_MSG} "You can also add the required PHP module later, if that's"
	@${ECHO_MSG} "what you prefer."
	@${ECHO_MSG} "
	@sleep 5
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MMSSQL}
USE_PHP+=	mssql
.endif

.if ${PORT_OPTIONS:MZLIB}
USE_PHP+=	zlib
.endif

.if ${PORT_OPTIONS:MNETWORK}
USE_PHP+=	openssl
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
MOODLEDATADIR?=	www/moodledata

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MOODLEDIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MOODLEDIR}?g" >> ${PLIST}
	@${ECHO} @dirrm ${MOODLEDATADIR} >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MOODLEDIR}
	@${FIND} ${STAGEDIR}${PREFIX}/${MOODLEDIR} -type d -exec ${CHMOD} a+x {} \;
	@${ECHO_CMD} '@exec ${FIND} ${PREFIX}/${MOODLEDIR} -type d -exec ${CHMOD} a+x {} \;' \
		>> ${TMPPLIST}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${MOODLEDATADIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${MOODLEDATADIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MOODLEDATADIR}' \
		>> ${TMPPLIST}
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/${MOODLEDATADIR}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/${MOODLEDATADIR}' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MMIMETEX}
	${LN} -sf ../../../cgi-bin/mimetex.cgi ${STAGEDIR}${PREFIX}/${MOODLEDIR}/filter/tex/mimetex.freebsd
.endif

.include <bsd.port.mk>
