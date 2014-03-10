# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pligg
PORTVERSION=	1.1.5
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://forums.pligg.com/attachments/current-version/
DISTNAME=	3076d1308851225-pligg-content-management-system-${PORTVERSION:S/./-/g}-pligg-cms-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An Open Source Web2.0 CMS

PORTSCOUT=	ignore:1

USES=		zip
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/pligg

NO_BUILD=	yes
SUB_FILES=	pkg-message

NO_STAGE=	yes
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
