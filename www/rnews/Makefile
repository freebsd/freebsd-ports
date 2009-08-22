# New ports collection makefile for:	rnews
# Date created:		22 December 2003
# Whom:			Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	rnews
PORTVERSION=	0.92
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	as@bsdgroup.de
COMMENT=	A server-side rss aggregator written in php with mysql

NO_BUILD=	yes

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
PORTDOCS=	CHANGELOG INSTALL LICENSE README UPGRADE
.endif

CONFIGS=	inc/config.php inc/config_user.php

do-install:
	@${FIND} -s ${WRKSRC} -type  d | ${SED} -e 's,^${WRKSRC},${WWWDIR},' \
		| ${XARGS} ${MKDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.php ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.js ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/.htaccess ${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/img/*.gif ${WWWDIR}/img
	${INSTALL_DATA} ${WRKSRC}/img/*.png ${WWWDIR}/img
	${INSTALL_DATA} ${WRKSRC}/img/*.jpg ${WWWDIR}/img
	( ${FIND} ${WRKSRC}/inc -type f -not -name config_user.php -a -not -name config.php; ${ECHO} ${WWWDIR}/inc ) \
		| ${XARGS} ${INSTALL_DATA} -v
	${INSTALL_DATA} -v ${WRKSRC}/magpierss/*.inc ${WWWDIR}/magpierss
	${INSTALL_DATA} ${WRKSRC}/magpierss/extlib/Snoopy.class.inc ${WWWDIR}/magpierss/extlib
	@${CHOWN} ${WWWOWN} ${WWWDIR}/magpierss/cache
	@${CHOWN} ${WWWOWN} ${WWWDIR}/img/feeds
.for FILE in ${CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${WWWDIR}/${FILE}.sample
.endfor

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
	@${FIND} -s ${WRKSRC} \( -name "*.php" -o -name "*.inc" -o -name "*.js" -o -name "*.css" -o -name "*.jpg" \
		-o -name "*.gif" -o -name "*.png" -o -name ".htaccess" \) -and -not -name config_user.php \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
.for FILE in ${CONFIGS}
	@${ECHO_CMD} '@exec if [ ! -f %D/%%WWWDIR%%/${FILE} ]; then \
		${INSTALL_DATA} %D/%%WWWDIR%%/${FILE}.sample %D/%%WWWDIR%%/${FILE}; \
		${CHOWN} ${WWWOWN} %D/%%WWWDIR%%/${FILE}; \
		${CHMOD} u+w %D/%%WWWDIR%%/${FILE}; fi' >> ${PLIST}
.endfor
.for FILE in ${CONFIGS}
	@${ECHO_CMD} '@unexec if cmp -s %D/%%WWWDIR%%/${FILE}.sample %D/%%WWWDIR%%/${FILE}; \
		then ${RM} -f %D/%%WWWDIR%%/${FILE}; fi' >> ${PLIST}
	@${ECHO_CMD} '%%WWWDIR%%/${FILE}.sample' >> ${PLIST}
.endfor
	@${ECHO_CMD} '@unexec if [ $$(ls %D/%%WWWDIR%%/img/feeds/|wc -w) -eq 0 ]; then ${RM} -rf %D/%%WWWDIR%%/img/feeds;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC} -type d -a -not -name feeds \
		| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.post.mk>
