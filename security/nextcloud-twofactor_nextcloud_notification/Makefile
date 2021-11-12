# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	twofactor_nextcloud_notification
PORTVERSION=	3.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	https://github.com/nextcloud-releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Use Nextcloud notification as MFA app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=17:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

NEXTCLOUD_USERNAME?=	${WWWOWN}
NEXTCLOUD_GROUPNAME?=	${WWWGRP}

PLIST_SUB=	NEXTCLOUD_USERNAME=${NEXTCLOUD_USERNAME} \
		NEXTCLOUD_GROUPNAME=${NEXTCLOUD_GROUPNAME}

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
