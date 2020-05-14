# Created by: Chin-San Huang <chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	dokuwiki
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g}
CATEGORIES=	www
MASTER_SITES=	http://download.dokuwiki.org/src/dokuwiki/
DISTNAME=	${DIST_VER}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Simple and easy to use wiki, no database required

LICENSE=			BSD3CLAUSE GPLv2 GPLv2+ GPLv3 MIT
LICENSE_COMB=			multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/vendor/simplepie/simplepie/LICENSE.txt
LICENSE_FILE_GPLv2=		${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =		${WRKSRC}/vendor/geshi/geshi/LICENSE
LICENSE_FILE_GPLv3=		${WRKSRC}/vendor/marcusschwarz/lesserphp/LICENSE
LICENSE_FILE_MIT=		${WRKSRC}/vendor/composer/LICENSE

DIST_VER=	${PORTNAME}-2018-04-22c
USES=		cpe tar:tgz php:web
USE_PHP=	gd hash json mbstring openssl pcre session xml zlib
NO_ARCH=	YES
NO_BUILD=	YES

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/bin/*.php
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${RM} ${WRKSRC}/data/deleted.files

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
