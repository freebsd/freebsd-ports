# New ports collection makefile for:	cakephp
# Date created:        19 January 2007
# Whom:                Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	cakephp
PORTVERSION=	1.1.13.4450
CATEGORIES=	www
MASTER_SITES=	http://cakeforge.org/frs/download.php/326/
DISTNAME=	cake_${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A framework for developing PHP web applications

USE_BZIP2=	yes
DISTFILE_SUFFIX=/donation=complete
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${TARGET_DISTFILE}

USE_APACHE=	2.0+
SLAVE_PORT_MODULES=	rewrite

NO_BUILD=	yes
USE_PHP=	pcre session
WANT_PHP_MOD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR}

WRKSRC=		${WRKDIR}/cake_${DISTVERSION}

OPTIONS=	PROD "Install for production server (see: make confighelp)" Off \
		MYSQL "Check for/install MySQL support in PHP" Off \
		PGSQL "Check for/install PostgreSQL support in PHP" Off \
		SQLITE "Check for/install SQLite support in PHP" Off

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-docs
.endif

.include <bsd.port.pre.mk>

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4.0 4.1 4.2 4.3.1

.if defined(WITH_PROD)
SUB_FILES+=	cakephp-production.conf
.else
SUB_FILES+=	cakephp-development.conf
EXTRA_PATCHES=	${FILESDIR}/development-app-config-core.php.patch
.endif

DB_DEFINED=	no

.if defined(WITH_MYSQL)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_mysql.so:${PORTSDIR}/databases/php5-pdo_mysql
DB_DEFINED=	yes
.endif

.if defined(WITH_PGSQL)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
DB_DEFINED=	yes
.endif

.if defined(WITH_SQLITE)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_sqlite.so:${PORTSDIR}/databases/php5-pdo_sqlite
DB_DEFINED=	yes
.endif

.if ${DB_DEFINED} == "yes"
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/php5-pdo \
		${DB_DEPENDS}
.endif

do-fetch:
.if !exists(${DISTDIR}/${TARGET_DISTFILE})
	${FETCH_CMD} ${FETCH_BEFORE_ARGS} -1 ${MASTER_SITES:S|$|${TARGET_DISTFILE}${DISTFILE_SUFFIX}|g}
.endif

confighelp:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "On a production server, the Apache DocumentRoot is"
	@${ECHO_MSG} "updated to point to the CakePHP webroot directory."
	@${ECHO_MSG} "In this configuration, the CakePHP application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "A non-production server, CakePHP is installed at"
	@${ECHO_MSG} "the /cakephp URL, and the CakePHP application is"
	@${ECHO_MSG} "accessed at http://www.myservername.com/cakephp/."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For more information, please see:"
	@${ECHO_MSG} "http://manual.cakephp.org/chapter/installing"
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/.htaccess \
			${WRKSRC}/app \
			${WRKSRC}/cake \
			${WRKSRC}/index.php \
			${WRKSRC}/vendors ${DATADIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
	${FIND} ${DATADIR} -type f -print | ${XARGS} -n1 ${CHMOD} 644
	${FIND} ${DATADIR} -type d -print | ${XARGS} -n1 ${CHMOD} 755

post-install:
.if exists(${PREFIX}/etc/apache2/Includes)
.if defined(WITH_PROD)
	@${CP} ${WRKDIR}/cakephp-production.conf ${PREFIX}/etc/apache2/Includes/cakephp.conf
.else
	@${CP} ${WRKDIR}/cakephp-development.conf ${PREFIX}/etc/apache2/Includes/cakephp.conf
.endif
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please check your Apache 2.x installation -"
	@${ECHO_MSG} "${PREFIX}/etc/apache2/Includes doesn't exist,"
	@${ECHO_MSG} "so I cannot install cakephp.conf there!"
	@${ECHO_MSG} ""
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
