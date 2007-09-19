# New ports collection makefile for:	moodle
# Date created:				30 September 2005
# Whom:					Javier Martin Rueda <jmrueda@diatel.upm.es>
#
# $FreeBSD$
#

PORTNAME=	moodle
PORTVERSION=	1.8.2
CATEGORIES=	www
MASTER_SITES=	http://download.moodle.org/stable18/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmrueda@diatel.upm.es
COMMENT=	Course management system based on social constructionism

USE_PHP=	session gd pcre mbstring iconv tokenizer curl xml
WRKSRC=		${WRKDIR}/moodle

OPTIONS=	MYSQL   "Add support for a MySQL database server" Off \
		PGSQL   "Add support for a PostgreSQL database server" Off \
		MSSQL   "Add support for a MS SQL Server" Off \
		ZLIB    "Add zip/unzip functionality" On \
		NETWORK "Add Moodle Network functionality" Off \
		LDAP    "Add LDAP authentication functionality" Off

.include <bsd.port.pre.mk>

.if !defined(WITH_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_MSSQL)
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

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_MSSQL)
USE_PHP+=	mssql
.endif

.if !defined(WITHOUT_ZLIB)
USE_PHP+=	zlib
.endif

.if defined(WITH_NETWORK)
USE_PHP+=	curl openssl
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
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
	${INSTALL_DATA} -d ${PREFIX}/${MOODLEDIR}
	${CP} -Rn ${WRKSRC}/* ${PREFIX}/${MOODLEDIR}
	${FIND} ${PREFIX}/${MOODLEDIR} -type d -exec ${CHMOD} a+x {} \;
	${MKDIR} ${PREFIX}/${MOODLEDATADIR}
	${CHOWN} www ${PREFIX}/${MOODLEDATADIR}
	${CHMOD} 755 ${PREFIX}/${MOODLEDATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
