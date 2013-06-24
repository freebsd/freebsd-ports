# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cakephp
PORTVERSION=	1.2.10
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/tarball/${PORTVERSION}/ \
		LOCAL/glarkin
DISTNAME=	${PORTNAME}-${PORTNAME}-${PORTVERSION}-${GITVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A framework for developing PHP web applications

LATEST_LINK=	cakephp12

GITVERSION=	0-ge6e50e8
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-da67eb8

PORTDOCS=	README

SLAVE_PORT_MODULES=	REWRITE

CONFLICTS=	cakephp-1.[13].* cakephp-2.*

NO_BUILD=	yes
USES=		gettext
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

OPTIONS_DEFINE=	PROD AP MYSQL PGSQL SQLITE APC MEMCACHE DOCS
PROD_DESC=	Install for production server (make confighelp)
APC_DESC=	APC caching engine
MEMCACHE_DESC=	Memcached caching engine client

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

.if ${PORT_OPTIONS:MAP}
SUB_FILES=	pkg-message
USE_APACHE_RUN=	22+
PKGMESSAGE=	pkg-message
APDEP=
.else
SUB_FILES=	pkg-message-no-apache
PKGMESSAGE=	pkg-message-no-apache
APDEP=		"@comment "
.endif

.if ${PORT_OPTIONS:MPROD}
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
		HTACCESS=${HTACCESS} APDEP=${APDEP}

DB_DEFINED=	no

.if ${PORT_OPTIONS:MMYSQL}
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_mysql.so:${PORTSDIR}/databases/php5-pdo_mysql
DB_DEFINED=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
DB_DEFINED=	yes
.endif

.if ${PORT_OPTIONS:MSQLITE}
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_sqlite.so:${PORTSDIR}/databases/php5-pdo_sqlite
DB_DEFINED=	yes
.endif

.if ${DB_DEFINED} == "yes"
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/php5-pdo \
		${DB_DEPENDS}
.endif

.if ${PORT_OPTIONS:MAPC}
USE_PHP+=	apc
.endif

.if ${PORT_OPTIONS:MMEMCACHE}
USE_PHP+=	memcache
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

.if ! ${PORT_OPTIONS:MPROD}
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
.if ${PORT_OPTIONS:MAP}
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
.endif
.if ${PORT_OPTIONS:MDOCS}
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
