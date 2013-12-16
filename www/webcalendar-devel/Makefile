# $FreeBSD$

PORTNAME=	WebCalendar
PORTVERSION=	1.2.5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}%201.2/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME:S/-devel//g}-${PORTVERSION}
PORTSCOUT=	limit:^1\.2\. skipb:1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web-based calendar application

USE_PHP=	pcre session
WANT_PHP_WEB=	yes
NO_BUILD=	yes
CONFLICTS=	WebCalendar-[0-9]*

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}
WWWDIR=		${PREFIX}/www/${PORTNAME:L}

OPTIONS_DEFINE=	APACHE LDAP GRADIENTBG REMINDERS PALM DOCS
OPTIONS_DEFAULT=	MYSQL REMINDERS
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE MSSQL DBASE ODBC ORACLE
GRADIENTBG_DESC=	Gradient background image support
REMINDERS_DESC=		Email reminder support
PALM_DESC=		Palm export support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}
PORTDOCS=	WebCalendar-SysAdmin.html \
		newwin.gif
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+

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

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite3
.endif

.if ${PORT_OPTIONS:MMSSQL}
USE_PHP+=	mssql
.endif

.if ${PORT_OPTIONS:MDBASE}
USE_PHP+=	dbase
.endif

.if ${PORT_OPTIONS:MODBC}
USE_PHP+=	odbc
.endif

.if ${PORT_OPTIONS:MORACLE}
USE_PHP+=	oracle
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MGRADIENTBG}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MREMINDERS}
WANT_PHP_CLI=	yes
.endif

.if ${PORT_OPTIONS:MPALM}
RUN_DEPENDS+=	${LOCALBASE}/bin/pilot-xfer:${PORTSDIR}/palm/pilot-link
.endif

.if ${PORT_OPTIONS:MDOCS}
SUB_LIST+=	HASHMARK=
.else
SUB_LIST+=	HASHMARK=\#
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
.if ${PORT_OPTIONS:MAPACHE}
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
.if ${PORT_OPTIONS:MDOCS}
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
