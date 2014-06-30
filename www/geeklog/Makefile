# Created by: Bob Bomar <bob@fly.homeunix.org>
# $FreeBSD$

PORTNAME=	geeklog
PORTVERSION=	1.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Web content management system

SUB_FILES=	pkg-message

USE_MYSQL=	yes

NO_BUILD=	yes
USE_PHP=	yes

do-install:
	@${INSTALL} -o ${WWWOWN} -g ${WWWGRP} -m 555 -d ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR} "! -name db-config.php \
			-or -name siteconfig.php")
	@${INSTALL_DATA} ${WRKSRC}/db-config.php ${STAGEDIR}${WWWDIR}/db-config.php.sample; 
	@${INSTALL_DATA} ${WRKSRC}/public_html/siteconfig.php \
			${STAGEDIR}${WWWDIR}/public_html/siteconfig.php.sample
	@${RM} ${STAGEDIR}${WWWDIR}/public_html/siteconfig.php

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
.for i in db-config.php error.log siteconfig.php geeklog.rss
	@${FIND} ${STAGEDIR}${WWWDIR} -name ${i} | ${XARGS} ${CHMOD} 755
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
