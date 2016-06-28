# Created by: Krzysztof Stryjek <ports@bsdserwis.com>
# $FreeBSD$

PORTNAME=	self-service-password
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://tools.ltb-project.org/attachments/download/497/
DISTNAME=	ltb-project-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Set of PHP-scripts to change LDAP password over the web

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	ldap openssl session hash hash mcrypt mbstring filter

WANT_PHP_WEB=	yes

CFGDIR=		conf
CFGFILE=	config.inc.php

PLIST_SUB+=	SSP_OWN=${WWWOWN}
PLIST_SUB+=	SSP_GRP=${WWWGRP}

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES=	pkg-message

post-extract:
	@${MV} ${WRKSRC}/${CFGDIR}/${CFGFILE} ${WRKSRC}/${CFGDIR}/${CFGFILE}.sample

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
