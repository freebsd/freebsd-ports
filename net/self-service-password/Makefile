# Created by: Krzysztof Stryjek <ports@bsdserwis.com>
# $FreeBSD$

PORTNAME=	self-service-password
PORTVERSION=	0.9
CATEGORIES=	net www

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Set of PHP-scripts to change LDAP password over the web

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ltb-project

USES=		php:web
USE_PHP=	filter hash ldap mbstring mcrypt openssl session

NO_BUILD=	yes
NO_ARCH=	yes

CFGDIR=		conf
CFGFILE=	config.inc.php

PLIST_SUB+=	SSP_OWN=${WWWOWN}
PLIST_SUB+=	SSP_GRP=${WWWGRP}

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES=	pkg-message

post-extract:
	@${MV} ${WRKSRC}/${CFGDIR}/${CFGFILE} ${WRKSRC}/${CFGDIR}/${CFGFILE}.sample
	@${RM} -r ${WRKSRC}/packaging/

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/ "-not -name checklang.pl"

.include <bsd.port.mk>
