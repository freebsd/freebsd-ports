# New ports collection makefile for:   piwik
# Date created:		31 Dec 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	piwik
PORTVERSION=	1.6
CATEGORIES=	www
MASTER_SITES=	http://builds.piwik.org/

MAINTAINER=	hans@nordhaug.priv.no
COMMENT=	A Open Source Web Analytics Software Program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/misc/gpl-3.0.txt

NO_BUILD=	yes
SUB_FILES=	pkg-message
USE_PHP=	dom gd iconv json mysql pdo pdo_mysql session xml zlib
WRKSRC=		${WRKDIR}/${PORTNAME}

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

.include <bsd.port.mk>
