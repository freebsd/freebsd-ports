# Created by: Krzysztof Stryjek <ports@bsdserwis.com>

PORTNAME=	self-service-password
DISTVERSION=	1.4.5
CATEGORIES=	net www
MASTER_SITES=	http://ltb-project.org/archives/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	ltb-project-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Set of PHP-scripts to change LDAP password over the web

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${LOCALBASE}/share/smarty3-${PHP_FLAVOR}/Smarty.class.php:www/smarty3@${PHP_FLAVOR}

USES=		php:flavors,web
USE_PHP=	filter hash ldap mbstring openssl phar session

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST+=	PKGNAME=${PKGNAME}

PLIST_SUB+=	SSP_GRP=${WWWGRP} \
		SSP_OWN=${WWWOWN}

CFGDIR=		conf
CFGFILE=	config.inc.php

.include <bsd.port.pre.mk>

.if ${PHP_VER} <= 70
# For older php mcrypt is needed
USE_PHP+=	mcrypt
.endif

post-extract:
	@${FIND} ${WRKSRC}/ -name '*.sig' -delete
	@${MV} ${WRKSRC}/${CFGDIR}/${CFGFILE} ${WRKSRC}/${CFGDIR}/${CFGFILE}.sample
	@${REINPLACE_CMD} \
		-e 's;/usr/share/php/smarty3;${PREFIX}/share/smarty3-${PHP_FLAVOR};' \
		${WRKSRC}/${CFGDIR}/${CFGFILE}.sample

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.post.mk>
