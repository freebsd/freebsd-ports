# New ports collection makefile for:   WebCalendar
# Date created:        21 June 2005
# Whom:                glarkin
#
# $FreeBSD$
#

PORTNAME=	WebCalendar
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webcalendar
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A web-based calendar application

USE_PHP=	pcre session
WANT_PHP_WEB=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

WCURL?=		${PORTNAME:L}
WCDIR?=		www/${WCURL}
PLIST=		${WRKDIR}/pkg-plist

SUB_FILES=	pkg-message
SUB_LIST=	WCURL=${WCURL} WCDIR=${WCDIR}

DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}
DOCS=		docs/README \
		docs/WebCalendar-Database.html \
		docs/WebCalendar-DeveloperGuide.html \
		docs/WebCalendar-Styling.html \
		docs/WebCalendar-SysAdmin.html \
		docs/newwin.gif

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
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WCDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WCDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WCDIR} >> ${PLIST}
	@${CAT} pkg-plist >> ${PLIST}
	@${ECHO_CMD} @dirrmtry www/data-dist >> ${PLIST}
	@${ECHO_CMD} @dirrmtry www/data >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${WCDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${WCDIR}
	${CHOWN} -R www:www ${PREFIX}/${WCDIR}
	${FIND} ${PREFIX}/${WCDIR} -type f | ${XARGS} ${CHMOD} 644

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
