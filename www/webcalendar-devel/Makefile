# New ports collection makefile for:	WebCalendar
# Date created:				08 Jan 2008
# Whom:					glarkin
#
# $FreeBSD$
#

PORTNAME=	WebCalendar
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}%201.2/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME:S/-devel//g}-${PORTVERSION}
PORTSCOUT=	limit:^1\.2\. skipb:1

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A web-based calendar application

USE_PHP=	pcre session
WANT_PHP_WEB=	yes
NO_BUILD=	yes
CONFLICTS=	WebCalendar-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}
WWWDIR=		${PREFIX}/www/${PORTNAME:L}

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}
PORTDOCS=	WebCalendar-SysAdmin.html \
		newwin.gif
.endif

OPTIONS=	APACHE "Configure for Apache-2.x" off \
		MYSQL "Use MySQL database backend (default)" On \
		PGSQL "Use PostgreSQL database backend" Off \
		MSSQL "Use MSSQL database backend" Off \
		DBASE "Use DBase database backend" Off \
		ODBC "Use ODBC database backend" Off \
		ORACLE "Use Oracle database backend" Off \
		LDAP "Use LDAP user authentication" Off \
		GRADIENTBG "Add gradient background image support" Off \
		REMINDERS "Add email reminder support" On \
		PALM "Add Palm export support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE)
USE_APACHE=	2.0+

PLIST_SUB+=	NOAPACHE="" CONFDIR=${CONFDIR_REL}
CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes
SUB_FILES=	pkg-message
.else
PLIST_SUB+=	NOAPACHE="@comment "
.endif

WITH_PHP_CGI?=	/cgi-bin/php

.if ${PHP_SAPI:Mcgi} == "cgi" && ${PHP_SAPI:Mmod} == ""
CGI_EXT=	-cgi
.else
CGI_EXT=
.endif

DEFAULT_PHP_VER=5

SUB_LIST+=	PHPCGI=${WITH_PHP_CGI}

DB_DEFINED=	no

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
DB_DEFINED=	yes
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
DB_DEFINED=	yes
.endif

.if defined(WITH_MSSQL)
USE_PHP+=	mssql
DB_DEFINED=	yes
.endif

.if defined(WITH_DBASE)
USE_PHP+=	dbase
DB_DEFINED=	yes
.endif

.if defined(WITH_ODBC)
USE_PHP+=	odbc
DB_DEFINED=	yes
.endif

.if defined(WITH_ORACLE)
USE_PHP+=	oracle
DB_DEFINED=	yes
.endif

.if ${DB_DEFINED} == "no"
IGNORE=		please choose database backend by running 'make config'
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_GRADIENTBG)
USE_PHP+=	gd
.endif

.if defined(WITH_REMINDERS)
WANT_PHP_CLI=	yes
.endif

.if defined(WITH_PALM)
RUN_DEPENDS+=	${LOCALBASE}/bin/pilot-xfer:${PORTSDIR}/palm/pilot-link
.endif

.if defined(NOPORTDOCS)
SUB_LIST+=	HASHMARK=\#
.else
SUB_LIST+=	HASHMARK=
.endif

CONF=		webcalendar${CGI_EXT}.conf
SUB_FILES+=	${CONF}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

post-install:
.if defined(WITH_APACHE)
	@if [ -d "${CONFDIR}" ]; then \
	  ${CP} ${WRKDIR}/${CONF} ${CONFDIR}/webcalendar.conf; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache 2.x installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install webcalendar.conf there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi
	@${CAT} ${PKGMESSAGE}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${CGI_EXT} == "-cgi"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Your WebCalendar installation was configured to use the PHP CGI binary."
	@${ECHO_MSG}	"The PHP CGI binary is expected to be referenced by the URL:"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"       ${WITH_PHP_CGI}"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"If this is incorrect, reinstall the port with the WITH_ PHP_CGI knob"
	@${ECHO_MSG}	"set to the correct URL."
	@${ECHO_MSG}	"*********************************************************************"
.endif

.include <bsd.port.post.mk>
