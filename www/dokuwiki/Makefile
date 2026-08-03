PORTNAME=	dokuwiki
DIST_VER=	${PORTNAME}-2026-07-14a
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g}
CATEGORIES=	www
MASTER_SITES=	http://download.dokuwiki.org/src/dokuwiki/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${DIST_VER}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Simple and easy to use wiki, no database required
WWW=		https://www.dokuwiki.org/

LICENSE=	BSD3CLAUSE GPLv2 GPLv2+ GPLv3 MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/vendor/simplepie/simplepie/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/vendor/geshi/geshi/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/vendor/composer/LICENSE

USES=		cpe php:web,flavors shebangfix tar:tgz
USE_PHP=	ctype filter gd iconv mbstring session simplexml xml zlib

SHEBANG_FILES=	bin/*.php
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}
REINPLACE_ARGS=	-i ''
NO_ARCH=	YES
NO_BUILD=	YES
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

post-patch:
	@${RM} ${WRKSRC}/data/deleted.files

post-patch-TEST-off:
	@${FIND} ${WRKSRC} -type d -name '_test' -prune -exec ${RM} -rf {} \;
	@${RM} -rf ${WRKSRC}/lib/plugins/testing
	@${RM} ${WRKSRC}/lib/scripts/linkwiz.test.js
	@${RM} ${WRKSRC}/vendor/simplepie/simplepie/phpstan.dist.neon
	@${RM} -rf ${WRKSRC}/vendor/simplepie/simplepie/utils/PHPStan
	@${RMDIR} ${WRKSRC}/vendor/simplepie/simplepie/utils

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
