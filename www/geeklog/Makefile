# New ports collection makefile for:	GeekLog
# Date Created: 	22 April 2002
# Whom:			Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

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
	@${INSTALL} -o ${WWWOWN} -g ${WWWGRP} -m 555 -d ${WWWDIR}
	@(cd ${WRKSRC} && \
		${COPYTREE_SHARE} \* ${WWWDIR} "! -name db-config.php \
			-or -name siteconfig.php")
	@if [ ! -f ${WWWDIR}/db-config.php ]; then \
		${INSTALL_DATA} ${WRKSRC}/db-config.php ${WWWDIR}/db-config.php; \
	fi
	@if [ ! -f ${WWWDIR}/public_html/siteconfig.php ]; then \
		{INSTALL_DATA} ${WRKSRC}/public_html/siteconfig.php \
			${WWWDIR}/public_html/siteconfig.php; \
	fi

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
.for i in db-config.php error.log siteconfig.php geeklog.rss
	@${FIND} ${WWWDIR} -name ${i} | ${XARGS} ${CHMOD} 755
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
