# Created by: glarkin
# $FreeBSD$

PORTNAME=	WebCalendar
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}%201.0/${PORTVERSION}
PORTSCOUT=	limit:^1\.0\.

MAINTAINER=	ports@FreeBSD.org
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

OPTIONS_DEFINE=	LDAP DOCS
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL MSSQL DBASE ODBC ORACLE
OPTIONS_DEFAULT=	MYSQL
DB_DESC=	Database backend
DBASE_DESC=	DBase database support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}
PORTDOCS=	README \
		WebCalendar-Database.html \
		WebCalendar-DeveloperGuide.html \
		WebCalendar-Styling.html \
		WebCalendar-SysAdmin.html \
		newwin.gif
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
