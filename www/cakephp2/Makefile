# New ports collection makefile for:	cakephp-devel
# Date created:        20 December 2007
# Whom:                Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cakephp
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://cakeforge.org/frs/download.php/733/ \
		LOCAL/glarkin
DISTNAME=	cake_${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A framework for developing PHP web applications

USE_BZIP2=	yes
DISTFILE_SUFFIX=/donation=complete
FETCH_BEFORE_ARGS=	-o -
TARGET_DISTFILE=${DISTNAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/cake_${PORTVERSION}

PORTDOCS=	README

USE_APACHE=	2.0+
SLAVE_PORT_MODULES=	rewrite

CONFLICTS=	cakephp-1.[13].*

NO_BUILD=	yes
USE_GETTEXT=	yes
USE_PHP=	session
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

CAKE_CONF_FILES=	\
		app/config/acl.ini.php \
		app/config/bootstrap.php \
		app/config/core.php \
		app/config/database.php \
		app/config/inflections.php \
		app/config/routes.php
CAKE_CONSOLE=	cake/console/cake

SUB_FILES=	pkg-message

OPTIONS=	PROD "Install for production server (make confighelp)" Off \
		MYSQL "Check for/install MySQL support in PHP" Off \
		PGSQL "Check for/install PostgreSQL support in PHP" Off \
		SQLITE "Check for/install SQLite support in PHP" Off \
		APC "Enable APC caching engine" Off \
		MEMCACHE "Enable Memcached caching engine client" Off

CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes

.include <bsd.port.pre.mk>

WITH_PHP_CGI?=	/cgi-bin/php

.if ${PHP_SAPI:Mcgi} == "cgi" && ${PHP_SAPI:Mmod} == ""
CGI_EXT=	-cgi
.else
CGI_EXT=
.endif

SUB_LIST+=	PHPCGI=${WITH_PHP_CGI}

.if defined(WITH_PROD)
PROD=		production
HTACCESS=	""
.else
PROD=		development
EXTRA_PATCHES=	${FILESDIR}/extra-patch-app__config__core.php
HTACCESS=	"@comment "
.endif

CONF=		cakephp-${PROD}${CGI_EXT}.conf
SUB_FILES+=	${CONF}

PLIST_SUB+=	CONFDIR=${CONFDIR_REL} ECHO_MSG=${ECHO_MSG} \
		HTACCESS=${HTACCESS}

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

.if defined(WITH_APC)
USE_PHP+=	apc
.endif

.if defined(WITH_MEMCACHE)
USE_PHP+=	memcache
.endif

do-fetch:
	@${INSTALL} -d ${DISTDIR}
.if !exists(${DISTDIR}/${TARGET_DISTFILE})
# Ok, this is a bit strange.  Since the cakeforge.org download URL has a
# PATH_INFO element at the end of it, the -o argument to fetch(1) is
# treated as a directory instead of a filename.  Instead of using
# "-o ${DISTDIR}/${TARGET_DISTFILE}", I have to use "-o -" and redirect
# stdout to the actual filename.
	@${FETCH_CMD} ${FETCH_BEFORE_ARGS} -1 ${MASTER_SITES:S|$|${TARGET_DISTFILE}${DISTFILE_SUFFIX}|g} | ${CAT} > ${DISTDIR}/${TARGET_DISTFILE}
	@${ECHO_MSG} ${TARGET_DISTFILE} has been downloaded.
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

post-extract:
	@${FIND} ${WRKSRC} -name ._\* -delete

post-patch:
	@${RM} ${WRKSRC}/cake/console/cake.orig

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \
		".htaccess app cake index.php vendors" ${WWWDIR}

.if !defined(WITH_PROD)
# If installed in development mode, get rid of .htaccess files,
# as noted by:
# http://book.cakephp.org/view/42/The-Configuration-Class#CakePHP-Core-Configuration-Variables-44
	@${FIND} ${WWWDIR} -type f -name .htaccess -exec ${RM} {} \;
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR:S|^${PREFIX}/|%D/|} -type f -name .htaccess -exec ${RM} {} \;' >> ${TMPPLIST}
.endif

# Get rid of the empty placeholder files
	@${FIND} ${WWWDIR} -type f -name empty -size 0 -exec ${RM} {} \;
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR:S|^${PREFIX}/|%D/|} -type f -name empty -size 0 -exec ${RM} {} \;' >> ${TMPPLIST}

	@for i in ${CAKE_CONF_FILES}; do \
		if [ -f ${WRKSRC}/$$i.default -a ! -f ${WRKSRC}/$$i ]; then \
			${INSTALL_DATA} ${WRKSRC}/$$i.default ${WWWDIR}/$$i; \
		elif [ -f ${WRKSRC}/$$i -a ! -f ${WRKSRC}/$$i.default ]; then \
			${INSTALL_DATA} ${WRKSRC}/$$i ${WWWDIR}/$$i.default; \
		fi \
	done
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

# Fix the permissions of the Cake console script
	@${CHMOD} 755 ${WWWDIR}/${CAKE_CONSOLE}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${WWWDIR}/${CAKE_CONSOLE}' >> ${TMPPLIST}

post-install:
	@if [ -d "${CONFDIR}" ]; then \
	  ${CP} ${WRKDIR}/${CONF} ${CONFDIR}/cakephp.conf; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache 2.x installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install cakephp.conf there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}
.if ${CGI_EXT} == "-cgi"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Your CakePHP installation was configured to use the PHP CGI binary."
	@${ECHO_MSG}	"The PHP CGI binary is expected to be referenced by the URL:"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"	${WITH_PHP_CGI}"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"If this is incorrect, reinstall the port with the WITH_PHP_CGI knob"
	@${ECHO_MSG}	"set to the correct URL."
.endif
	@${ECHO_MSG}	"*********************************************************************"

.include <bsd.port.post.mk>
