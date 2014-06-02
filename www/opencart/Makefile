# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	opencart
PORTVERSION=	1.5.6.4
CATEGORIES=	www misc

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An open source PHP-based online shopping cart system

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	opencart
GH_COMMIT=	31323f8

USE_PHP=	mysql gd session pcre
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${GH_COMMIT}/upload

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}' \
		>> ${TMPPLIST}
	@${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}/image/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}/image/' \
		>> ${TMPPLIST}

post-install:
	@${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}/system/cache/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}/system/cache/' \
		>> ${TMPPLIST}
	@${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}/download/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}/download/' \
		>> ${TMPPLIST}
	@if [ ! -f ${STAGEDIR}${WWWDIR}/config.php ]; then \
	        ${CP} -p ${STAGEDIR}${WWWDIR}/config-dist.php \
		${STAGEDIR}${WWWDIR}/config.php; fi
	@${CHMOD} 0755 ${STAGEDIR}${WWWDIR}/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 0755 ${STAGEDIR}${WWWDIR}/config.php' \
		>> ${TMPPLIST}
	@if [ ! -f ${STAGEDIR}${WWWDIR}/admin/config.php ]; then \
	        ${CP} -p ${STAGEDIR}${WWWDIR}/admin/config-dist.php \
		${STAGEDIR}${WWWDIR}/admin/config.php; fi
	@${CHMOD} 0755 ${STAGEDIR}${WWWDIR}/admin/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 0755 ${STAGEDIR}${WWWDIR}/admin/config.php' \
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
