# New ports collection makefile for:	vtiger
# Date created:			Fri Mar 11 20:59:31 EST 2005
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	vtiger
PORTVERSION=	5.0.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}crm/${PORTNAME}%20CRM%20${PORTVERSION}/Core%20%20Product
DISTFILES=	${PORTNAME}crm-${DISTVERSION}.tar.gz \
		${PORTNAME}CRM-${DISTVERSION}-PHP5.2-Patch1.tar.gz

MAINTAINER=	as@bsdgroup.de
COMMENT=	Vtiger CRM is open source Customer Relationship Management software

NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/vtigercrm

OPTIONS=	MYSQLSERVER     "Use MySQL-Server on localhost" OFF

.include <bsd.port.pre.mk>

USE_PHP=	mysql gd imap session pcre xml
WANT_PHP_WEB=	YES
IGNORE_WITH_PHP=	4
IGNORE_WITH_MYSQL=	323 40

CONFLICTS=	vtiger-4.*

.if !defined(WITHOUT_MYSQLSERVER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Release_Notes.html DEPENDENCIES.txt README.txt
.endif

CONFIGS=	config.db.php config.inc.php config.php config.template.php
DIRS=		themes modules include Image cron log4php adodb Smarty \
		license test jscalendar schema cache data install database \
		logs user_privileges soap class_http storage class_http_dir
PATCHDIRS=	data include include/utils modules/Migration modules/Migration/DBChanges
WRITEABLES=	cache storage install tabdata.php parent_tabdata.php \
		install.php user_privileges Smarty/cache Smarty/templates_c \
		modules/Emails/templates/ test/wordtemplatedownload test/product/ \
		test/user test/contact test/logo logs modules/Webmails/tmp

do-patch:
.for DIR in ${PATCHDIRS}
	@${INSTALL_DATA} -v ${WRKDIR}/${DIR}/*.php ${WRKSRC}/${DIR}
.endfor

do-install:
.for DIR in ${DIRS}
	${MKDIR} ${WWWDIR}/${DIR}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${WWWDIR} )
.endfor
	@( ${FIND} ${WRKSRC} -type f -maxdepth 1 \( -name \*.php -or -name \*.properties \
		-or -name Copyright.txt \) -and -not -name config\* ; ${ECHO} ${WWWDIR} ) \
		| ${XARGS} ${INSTALL_DATA} -v
.for FILE in ${CONFIGS}
	${INSTALL_DATA}	${WRKSRC}/${FILE} ${WWWDIR}/${FILE}.sample
.endfor
.for FILE in ${WRITEABLES}
	@${CHOWN} -R ${WWWOWN} ${WWWDIR}/${FILE}
	@${CHMOD} -R u+w ${WWWDIR}/${FILE}
.endfor
	@( cd ${WWWDIR} && ${CHMOD} u+w install.php tabdata.php parent_tabdata.php )

post-install:
.for FILE in ${CONFIGS}
. if !exists(${WWWDIR}/${FILE})
	${INSTALL_DATA} ${WWWDIR}/${FILE}.sample ${WWWDIR}/${FILE}
	@${CHOWN} ${WWWOWN} ${WWWDIR}/${FILE}
	@${CHMOD} u+w ${WWWDIR}/${FILE}
. endif
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC} -type f -mindepth 2 \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${FIND} -s ${WRKSRC} -type f \( -maxdepth 1 \( -name \*.php -or -name \*.properties \
		-or -name Copyright.txt \) -and -not -name config\* \) \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' >> ${PLIST}
.for FILE in ${CONFIGS}
	@${ECHO_CMD} '@unexec if cmp -s %D/%%WWWDIR%%/${FILE}.sample %D/%%WWWDIR%%/${FILE}; \
		then ${RM} -f %D/%%WWWDIR%%/${FILE}; fi' >> ${PLIST}
.endfor
	@${FIND} -s ${WRKSRC} -type f -maxdepth 1 -name config\* \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' -e 's,$$,.sample,' >> ${PLIST}
.for FILE in ${CONFIGS}
	@${ECHO_CMD} '@exec if [ ! -f %D/%%WWWDIR%%/${FILE} ]; then \
		${INSTALL_DATA} %D/%%WWWDIR%%/${FILE}.sample %D/%%WWWDIR%%/${FILE}; \
		${CHOWN} ${WWWOWN} %D/%%WWWDIR%%/${FILE}; \
		${CHMOD} u+w %D/%%WWWDIR%%/${FILE}; fi' >> ${PLIST}
.endfor
	@${ECHO_CMD} '@exec (cd %D/%%WWWDIR%% && \
		${CHMOD} u+w install.php tabdata.php parent_tabdata.php )' >> ${PLIST}
	@${FIND} ${WRKSRC} -type d -empty \
		| ${SED} -e 's,^${WRKSRC},@exec ${MKDIR} %D/%%WWWDIR%%,' >> ${PLIST}
.for FILE in ${WRITEABLES}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN} %D/%%WWWDIR%%/${FILE}; \
		${CHMOD} -R u+w %D/%%WWWDIR%%/${FILE}' >> ${PLIST}
.endfor
	@${FIND} -ds ${WRKSRC} -type d \
		| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.post.mk>
