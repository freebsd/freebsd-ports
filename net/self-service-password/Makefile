# Created by: Krzysztof Stryjek <ports@bsdserwis.com>
# $FreeBSD$

PORTNAME=	self-service-password
DISTVERSION=	1.3
CATEGORIES=	net www
MASTER_SITES=	http://ltb-project.org/archives/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	ltb-project-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Set of PHP-scripts to change LDAP password over the web

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		php:flavors,web
USE_PHP=	filter hash ldap mbstring openssl phar session

NO_BUILD=	yes
NO_ARCH=	yes

CFGDIR=		conf
CFGFILE=	config.inc.php

PLIST_SUB+=	SSP_OWN=${WWWOWN}
PLIST_SUB+=	SSP_GRP=${WWWGRP}

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PHP_VER} <= 70
# For older php mcrypt is needed
USE_PHP+=	mcrypt
.endif

post-extract:
	@${FIND} ${WRKSRC}/ -name '*.sig' -delete
	@${MV} ${WRKSRC}/${CFGDIR}/${CFGFILE} ${WRKSRC}/${CFGDIR}/${CFGFILE}.sample

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.post.mk>
