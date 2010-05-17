# New ports collection makefile for:   piwik
# Date created:		31 Dec 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	piwik
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://builds.piwik.org/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Open Source Web Analytics Software Program

USE_PHP=	mysql gd pdo pdo_mysql zlib iconv dom json session xml
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
pre-install:
	@if [ ! -f ${LOCALBASE}/bin/php ]; then \
		echo " It seems you install php without CLI enabled. "; \
		echo " It will cause problem when use piwik. "; \
		echo " If you want to reconsider, press Ctrl-C now to cancel. "; \
		echo " Then reinstall php with CLI enabled. "; \
		sleep 3; \
	fi

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
