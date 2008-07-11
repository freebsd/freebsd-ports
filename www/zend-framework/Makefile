# New ports collection makefile for:	zend-framework
# Date created:		31 October 2006
# Whom:			Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	ZendFramework
PORTVERSION=	1.5.2
CATEGORIES=	www
MASTER_SITES=	http://framework.zend.com/releases/${DISTNAME}/ GENTOO/distfiles

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A framework for developing PHP web applications

NO_BUILD=	yes
USE_PHP=	pcre spl
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

OPTIONS=	MYSQL "Install MySQL PDO support" Off \
		DBLIB "Install DBLIB PDO support" Off \
		PGSQL "Install PostgreSQL PDO support" Off \
		OCI "Install Oracle OCI 8 PDO support" Off \
		ODBC "Install ODBC PDO support" Off \
		SQLITE "Install SQLite v3 PDO support" Off \
		REQPHP "Install required PHP dependencies" On \
		OPTPHP "Install optional PHP dependencies" Off

.include <bsd.port.pre.mk>

IGNORE_WITH_PHP=4

# Add all of the required and/or optional PHP extension dependencies,
# if chosen by the user.
#
# See http://framework.zend.com/manual/en/requirements.extensions.html for
# a table of what PHP extensions are required for what ZF classes.

.if defined(WITH_REQPHP)
USE_PHP+=	apc ctype curl dom gd hash iconv mbstring \
		memcache pdo session simplexml soap xml zlib
.endif
.if defined(WITH_OPTPHP)
USE_PHP+=	bcmath bitset json posix
.endif

.if defined(WITH_MYSQL)
USE_PHP+=	pdo_mysql
.endif

.if defined(WITH_DBLIB)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:${PORTSDIR}/databases/php5-pdo_dblib
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if defined(WITH_OCI)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_oci.so:${PORTSDIR}/databases/php5-pdo_oci
.endif

.if defined(WITH_ODBC)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php5-pdo_odbc
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	pdo_sqlite
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${DATADIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
