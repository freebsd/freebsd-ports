# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	opencart
PORTVERSION=	1.5.4.1
CATEGORIES=	www misc
MASTER_SITES=	https://github.com/downloads/opencart/opencart/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An open source PHP-based online shopping cart system

#PROJECTHOST=	open-cart
USE_GITHUB=	yes
GH_ACCOUNT=	opencart
USES=		zip
USE_PHP=	mysql gd session pcre
WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION}/upload

NO_BUILD=	yes
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CHMOD} -R 0755 ${WWWDIR}/image/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${WWWDIR}/image/' \
		>> ${TMPPLIST}
	@${CHMOD} -R 0755 ${WWWDIR}/system/cache/
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${WWWDIR}/system/cache/' \
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
