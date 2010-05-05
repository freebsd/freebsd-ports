# New ports collection makefile for:   WebCalendar
# Date created:        21 June 2005
# Whom:                glarkin
#
# $FreeBSD$
#

PORTNAME=	WebCalendar
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}%201.0/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}
PORTSCOUT=	limit:^1\.0\.

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A web-based calendar application

USE_PHP=	pcre session
WANT_PHP_WEB=	yes
NO_BUILD=	yes
CONFLICTS=	WebCalendar-devel-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

WCURL?=		webcalendar
WCDIR?=		www/${WCURL}
PLIST=		${WRKDIR}/pkg-plist

SUB_FILES=	pkg-message
SUB_LIST=	WCURL=${WCURL} WCDIR=${WCDIR}

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}
PORTDOCS=	README \
		WebCalendar-Database.html \
		WebCalendar-DeveloperGuide.html \
		WebCalendar-Styling.html \
		WebCalendar-SysAdmin.html \
		newwin.gif
.endif

OPTIONS=	MYSQL "Use MySQL database backend (default)" On \
		PGSQL "Use PostgreSQL database backend" Off \
		MSSQL "Use MSSQL database backend" Off \
		DBASE "Use DBase database backend" Off \
		ODBC "Use ODBC database backend" Off \
		ORACLE "Use Oracle database backend" Off \
		LDAP "Use LDAP user authentication" Off

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

pre-install:
	@cd ${WRKSRC} && ${FIND} -s * -type f | \
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
		${WCDIR:S|^|%D/|}' >> ${TMPPLIST}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
