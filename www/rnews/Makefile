# New ports collection makefile for:	rnews
# Date created:		22 December 2003
# Whom:			Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	rnews
PORTVERSION=	0.80
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	as@bsdgroup.de
COMMENT=	A server-side rss aggregator written in php with mysql

NO_BUILD=	yes

WWWDIR?=	${PREFIX}/www/${PORTNAME}

SUB_FILES=	pkg-message

OPTIONS=	GD		"Enable Graphic (GD) support"	ON \
		MYSQLSERVER	"Use MySQL-Server on localhost"	OFF

.include <bsd.port.pre.mk>

USE_PHP=	mysql mbstring pcre xml iconv
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323 40

.if !defined(WITHOUT_GD)
USE_PHP+=	gd
.endif

.if !defined(WITHOUT_MYSQLSERVER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGELOG INSTALL README UPGRADE
.endif

do-install:
	@${FIND} -s ${WRKSRC} -type  d | ${SED} -e 's,^${WRKSRC},${WWWDIR},' \
		| ${XARGS} ${MKDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.php ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/rnews-side.css ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/ajax.js ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/.htaccess ${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/img/*.gif ${WWWDIR}/img
	${INSTALL_DATA} ${WRKSRC}/img/xml.png ${WWWDIR}/img
	( ${FIND} ${WRKSRC}/inc -name '*.php' -not -name config_user.php; ${ECHO} ${WWWDIR}/inc ) \
		| ${XARGS} ${INSTALL_DATA} -v
	${INSTALL_DATA} ${WRKSRC}/inc/.htaccess ${WWWDIR}/inc
	${INSTALL_DATA} -v ${WRKSRC}/magpierss/*.inc ${WWWDIR}/magpierss
	${INSTALL_DATA} ${WRKSRC}/magpierss/extlib/Snoopy.class.inc ${WWWDIR}/magpierss/extlib
	@${CHOWN} ${WWWOWN} ${WWWDIR}/magpierss/cache
	@${CHOWN} ${WWWOWN} ${WWWDIR}/img/feeds
.if !exists(${WWWDIR}/inc/config_user.php)
	@${TOUCH} ${WWWDIR}/inc/config_user.php
	@${CHOWN} ${WWWOWN} ${WWWDIR}/inc/config_user.php
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.	endfor
.endif
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC} \( -name "*.php" -o -name "*.inc" -o -name "*.js" -o -name "*.css" \
		-o -name "*.gif" -o -name "*.png" -o -name ".htaccess" \) -and -not -name config_user.php \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@exec ${TOUCH} %D/%%WWWDIR%%/inc/config_user.php;${CHOWN} ${WWWOWN} %D/%%WWWDIR%%/inc/config_user.php' >> ${PLIST}
	@${ECHO_CMD} '@unexec if [ ! -s %D/%%WWWDIR%%/inc/config_user.php ];then ${RM} -f %D/%%WWWDIR%%/inc/config_user.php;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC} -type d \
		| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.post.mk>
