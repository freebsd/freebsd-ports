# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ZendFramework
PORTVERSION=	1.12.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://packages.zendframework.com/releases/${DISTNAME}/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Framework for developing PHP web applications

LICENSE=	BSD

NO_BUILD=	yes
USE_PHP=	spl
WANT_PHP_WEB=	yes
USES=		gettext

CONFLICTS=	ZendFramework-2.*

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES MYSQL MYSQLI DBLIB PGSQL ODBC SQLITE REQPHP OPTPHP
OPTIONS_DEFAULT=REQPHP

MYSQL_DESC=	Enable MySQL PDO support
MYSQLI_DESC=	Enable MySQLi support
DBLIB_DESC=	Enable DBLIB PDO support
PGSQL_DESC=	Enable PostgreSQL PDO support
ODBC_DESC=	Enable ODBC PDO support
SQLITE_DESC=	Enable SQLite v3 PDO support
REQPHP_DESC=	Install required PHP dependencies
OPTPHP_DESC=	Install optional PHP dependencies

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-manual-en${EXTRACT_SUFX}
.endif

INSTALL_DIRS=	library extras/library externals/dojo/dijit \
		externals/dojo/dojo externals/dojo/dojox \
		externals/dojo/util

# Add all of the required and/or optional PHP extension dependencies,
# if chosen by the user.
#
# See http://framework.zend.com/manual/1.12/en/requirements.introduction.html
# for a table of what PHP extensions are required for what ZF classes.

.if ${PORT_OPTIONS:MREQPHP}
USE_PHP+=	apc ctype curl dom gd hash iconv mbstring ldap mcrypt \
		pcre pdo session simplexml soap \
		wddx xml zlib
.if ${PHP_VER} == 52
USE_PHP+=	sqlite
.else
USE_PHP+=	sqlite3
.endif
RUN_DEPENDS+=	pecl-memcache>=0:${PORTSDIR}/databases/pecl-memcache \
		pecl-memcached>=0:${PORTSDIR}/databases/pecl-memcached
.endif
.if ${PORT_OPTIONS:MOPTPHP}
USE_PHP+=	bcmath bitset json posix
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MDBLIB}
USE_PHP+=	pdo_dblib
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql
.endif

.if ${PORT_OPTIONS:MODBC}
USE_PHP+=	pdo_odbc
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${INSTALL_DIRS}" ${DATADIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${DATADIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
	@cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} zf.sh ${PREFIX}/bin/zf
	@cd ${WRKSRC}/bin && ${INSTALL_DATA} zf.php ${PREFIX}/bin/zf.php
.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "demos tests" ${EXAMPLESDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EXAMPLESDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${EXAMPLESDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${EXAMPLESDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${EXAMPLESDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
.endif

# Maintainer-mode target to speed up fixup of output from genplist
fix-new-plist:
	@if [ -f pkg-plist.new ]; then \
		${PERL} -ni.bak -e \
				's#^(.*%%DATADIR%%/externals)#%%DOJO%%$$1#g; \
				print;' pkg-plist.new; \
	else \
		${ECHO_CMD} Please run genplist to create pkg-plist.new; \
	fi

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "INSTALL.txt README.txt" ${DOCSDIR}
	@${INSTALL} -d ${DOCSDIR}/manual
	@cd ${WRKSRC}/documentation/manual/core/en && \
		${COPYTREE_SHARE} . ${DOCSDIR}/manual
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
