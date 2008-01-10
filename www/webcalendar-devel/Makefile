# New ports collection makefile for:	WebCalendar
# Date created:				08 Jan 2008
# Whom:					glarkin
#
# $FreeBSD$
#

PORTNAME=	WebCalendar
PORTVERSION=	1.1.6
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	webcalendar
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME:S/-devel//g}-${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A web-based calendar application

USE_PHP=	pcre session
WANT_PHP_WEB=	yes
NO_BUILD=	yes
CONFLICTS=	WebCalendar-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}

WCURL?=		${MASTER_SITE_SUBDIR}
WCDIR?=		www/${WCURL}
PLIST=		${WRKDIR}/pkg-plist

SUB_FILES=	pkg-message
SUB_LIST=	WCURL=${WCURL} WCDIR=${WCDIR}

DOCSDIR?=	${PREFIX}/share/doc/${MASTER_SITE_SUBDIR}
PORTDOCS=	WebCalendar-SysAdmin.html \
		newwin.gif

OPTIONS=	MYSQL "Use MySQL database backend (default)" On \
		PGSQL "Use PostgreSQL database backend" Off \
		MSSQL "Use MSSQL database backend" Off \
		DBASE "Use DBase database backend" Off \
		ODBC "Use ODBC database backend" Off \
		ORACLE "Use Oracle database backend" Off \
		LDAP "Use LDAP user authentication" Off \
		GRADIENTBG "Add gradient background image support" Off \
		REMINDERS "Add email reminder support" On

.include <bsd.port.pre.mk>

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

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WCDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WCDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WCDIR} >> ${PLIST}
	@${ECHO_CMD} @dirrmtry www/data-dist >> ${PLIST}
	@${ECHO_CMD} @dirrmtry www/data >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${WCDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${WCDIR}
	@${FIND} ${PREFIX}/${WCDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WCDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
