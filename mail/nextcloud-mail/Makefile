# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	mail
DISTVERSION=	1.11.5
DISTVERSIONPREFIX=	v
CATEGORIES=	mail
MASTER_SITES=	https://github.com/nextcloud-releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	nextcloud

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Mail app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=20:www/nextcloud@${PHP_FLAVOR}

USES=		cpe gettext php:flavors
USE_PHP=	imap

CPE_VENDOR=	nextcloud

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
	(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
