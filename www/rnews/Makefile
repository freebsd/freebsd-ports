# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	rnews
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server-side RSS aggregator written in PHP with MySQL

BROKEN_powerpc64=	Does not build

NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GD MYSQLSERVER DOCS
OPTIONS_DEFAULT=	GD
MYSQLSERVER_DESC=	Use MySQL-Server on localhost

.include <bsd.port.options.mk>

USE_PHP=	mysql mbstring pcre xml iconv

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MMYSQLSERVER}
USES+=		mysql:client,server
.else
USES+=		mysql
.endif

RUN_DEPENDS+=	curl:ftp/curl

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	CHANGELOG INSTALL LICENSE README UPGRADE
.endif

CONFIGS=	inc/config.php inc/config_user.php

do-install:
	@${FIND} -s ${WRKSRC} -type  d | ${SED} -e 's,^${WRKSRC},${STAGEDIR}${WWWDIR},' \
		| ${XARGS} ${MKDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.php ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.css ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.js ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/.htaccess ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/tmp/.htaccess ${STAGEDIR}${WWWDIR}/tmp
	${INSTALL_DATA} ${WRKSRC}/favicon.ico ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/help.html ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/img/*.gif ${STAGEDIR}${WWWDIR}/img
	${INSTALL_DATA} -v ${WRKSRC}/img/*.png ${STAGEDIR}${WWWDIR}/img
	${INSTALL_DATA} -v ${WRKSRC}/img/*.jpg ${STAGEDIR}${WWWDIR}/img
	( ${FIND} ${WRKSRC}/inc -type f -not -name config_user.php -a -not -name config.php; ${ECHO} ${STAGEDIR}${WWWDIR}/inc ) \
		| ${XARGS} ${INSTALL_DATA} -v
	${INSTALL_DATA} -v ${WRKSRC}/magpierss/*.inc ${STAGEDIR}${WWWDIR}/magpierss
	${INSTALL_DATA} ${WRKSRC}/magpierss/extlib/Snoopy.class.inc ${STAGEDIR}${WWWDIR}/magpierss/extlib
	${INSTALL_DATA} -v ${WRKSRC}/opml/*.opml ${STAGEDIR}${WWWDIR}/opml
.for FILE in ${CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${WWWDIR}/${FILE}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

create-plist:
	@${FIND} -s ${WRKSRC} \( -name "*.php" -o -name "*.inc" -o -name "*.js" -o -name "*.css" -o -name "*.jpg" \
		-o -name "*.gif" -o -name "*.png" -o -name ".htaccess" -o -name "help.html" -o -name "favicon.ico" -o -name "*.opml" \) \
		-and -not -name config_user.php -and -not -name config.php \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
.for FILE in ${CONFIGS}
	@${ECHO_CMD} '@sample(${WWWOWN},,) %%WWWDIR%%/${FILE}.sample' >> ${PLIST}
.endfor
.for DIR in magpierss/cache img/feeds tmp
	@${ECHO_CMD} '@dir(${WWWOWN},,) %%WWWDIR%%/${DIR}' >> ${PLIST}
.endfor

.include <bsd.port.mk>
