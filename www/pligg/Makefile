# New ports collection makefile for:   pligg
# Date created:		10 August 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pligg
PORTVERSION=	9.9.5
CATEGORIES=	www
MASTER_SITES=	http://forums.pligg.com/attachments/current-version/
DISTNAME=	1509d1217929605-pligg-beta-9-9-5-pligg-beta-9.9.5

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open Source Web2.0 CMS

USE_ZIP=	yes
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/Pligg\ Beta\ 9.9.5

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

	@if [ ! -f ${WWWDIR}/settings.php ]; then \
	${CP} -p ${WWWDIR}/settings.php.default ${WWWDIR}/settings.php; fi

	@if [ ! -f ${WWWDIR}/libs/dbconnect.php ]; then \
	${CP} -p ${WWWDIR}/libs/dbconnect.php.default \
		${WWWDIR}/libs/dbconnect.php; fi

	@${CHMOD} 666 ${WWWDIR}/settings.php
	@${ECHO_CMD} '@exec ${CHMOD} 666 ${WWWDIR}/settings.php' \
		>> ${TMPPLIST}

	@${CHMOD} 666 ${WWWDIR}/libs/dbconnect.php
	@${ECHO_CMD} '@exec ${CHMOD} 666 ${WWWDIR}/libs/dbconnect.php' \
		>> ${TMPPLIST}

	@${CHMOD} 655 ${WWWDIR}/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 655 ${WWWDIR}/config.php' \
		>> ${TMPPLIST}

.for d in backup cache templates templates_c avatars/user_uploaded
	@${CHMOD} 777 ${WWWDIR}/${d}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${WWWDIR}/${d}' >> ${TMPPLIST}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
