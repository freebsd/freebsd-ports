PORTNAME=	dokuwiki
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g}
CATEGORIES=	www
MASTER_SITES=	http://download.dokuwiki.org/src/dokuwiki/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${DIST_VER}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Simple and easy to use wiki, no database required
WWW=		https://www.dokuwiki.org/

LICENSE=			BSD3CLAUSE GPLv2 GPLv2+ GPLv3 MIT
LICENSE_COMB=			multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/vendor/simplepie/simplepie/LICENSE.txt
LICENSE_FILE_GPLv2=		${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =		${WRKSRC}/vendor/geshi/geshi/LICENSE
LICENSE_FILE_MIT=		${WRKSRC}/vendor/composer/LICENSE

DIST_VER=	${PORTNAME}-2025-05-14b
USES=		cpe php:web,flavors shebangfix tar:tgz
USE_PHP=	ctype filter gd iconv mbstring ldap pdo_mysql session simplexml xml zlib
NO_ARCH=	YES
NO_BUILD=	YES

SHEBANG_FILES=	bin/*.php
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

REINPLACE_ARGS=	-i ''

post-patch:
	@${RM} ${WRKSRC}/data/deleted.files

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
