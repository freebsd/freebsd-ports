# Created by: Bob Bomar <bob@fly.homeunix.org>
# $FreeBSD$

PORTNAME=	geeklog
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web content management system

LICENSE=	GPLv2+

USES=		cpe php

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

USE_MYSQL=	yes

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR} "! -name db-config.php \
			-or -name siteconfig.php")
	${INSTALL_DATA} ${WRKSRC}/db-config.php ${STAGEDIR}${WWWDIR}/db-config.php.sample
	${INSTALL_DATA} ${WRKSRC}/public_html/siteconfig.php \
			${STAGEDIR}${WWWDIR}/public_html/siteconfig.php.sample
	@${RM} ${STAGEDIR}${WWWDIR}/public_html/siteconfig.php
.for i in db-config.php error.log siteconfig.php geeklog.rss
	@${FIND} ${STAGEDIR}${WWWDIR} -name ${i} | ${XARGS} ${CHMOD} 755
.endfor

.include <bsd.port.mk>
