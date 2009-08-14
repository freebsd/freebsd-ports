# New ports collection makefile for:   opencart
# Date created:		04 April 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	opencart
PORTVERSION=	1.3.0
CATEGORIES=	www misc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	An open source PHP-based online shopping cart system

#PROJECTHOST=	open-cart
USE_ZIP=	yes
USE_PHP=	mysql gd session pcre
WRKSRC=		${WRKDIR}/${DISTNAME}/upload

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CHMOD} -R 0755 ${WWWDIR}/image/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${WWWDIR}/image/' \
		>> ${TMPPLIST}
	@${CHMOD} -R 0755 ${WWWDIR}/cache/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${WWWDIR}/cache/' \
		>> ${TMPPLIST}
	@${CHMOD} -R 0755 ${WWWDIR}/download/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${WWWDIR}/download/' \
		>> ${TMPPLIST}
	@${CHMOD} 0755 ${WWWDIR}/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 0755 ${WWWDIR}/config.php' \
		>> ${TMPPLIST}
	@${CHMOD} 0755 ${WWWDIR}/admin/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 0755 ${WWWDIR}/admin/config.php' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
