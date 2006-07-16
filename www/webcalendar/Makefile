# New ports collection makefile for:   WebCalendar
# Date created:        21 June 2005
# Whom:                glarkin
#
# $FreeBSD$
#

PORTNAME=	WebCalendar
DISTVERSION=	1.0.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webcalendar
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A web-based calendar application

BROKEN=		fails to deinstall cleanly

USE_PHP=	pcre session ldap
WANT_PHP_WEB=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/WebCalendar-${DISTVERSION}

WEBWCDIR?=	www/data/WebCalendar
PLIST=		${WRKDIR}/pkg-plist

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
		ORACLE "Use Oracle database backend" Off

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
IGNORE=		please, choose database backend running 'make config'
.endif

# Fix USE_PHP after bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.php.mk"

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WEBWCDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WEBWCDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WEBWCDIR} >> ${PLIST}
	@${CAT} pkg-plist >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${WEBWCDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${WEBWCDIR}
	${CHOWN} -R www:www ${PREFIX}/${WEBWCDIR}
	${FIND} ${PREFIX}/${WEBWCDIR} -type f | ${XARGS} ${CHMOD} 644

post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%WEBWCDIR%%|${WEBWCDIR}|g' -e 's|%%DOCSDIR%%|${DOCSDIR}|g'

.include <bsd.port.post.mk>
