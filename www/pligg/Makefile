# New ports collection makefile for:   pligg
# Date created:		10 August 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pligg
PORTVERSION=	1.0.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://forums.pligg.com/attachments/current-version/
DISTNAME=	2032d1245171709-pligg-content-management-system-1-0-0-pligg-cms-1.0.0

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open Source Web2.0 CMS

USE_ZIP=	yes
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/Pligg\ ${PORTVERSION}

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
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

.for d in admin/backup cache avatars/groups_uploaded avatars/user_uploaded languages
	@${CHMOD} -R 777 ${WWWDIR}/${d}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${WWWDIR}/${d}' >> ${TMPPLIST}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
