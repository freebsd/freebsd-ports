PORTNAME=	phplist
DISTVERSION=	3.6.16
CATEGORIES=	mail www
MASTER_SITES=	SF
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Full-featured open-source newsletter manager
WWW=		https://www.phplist.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR}

USES=		cpe tar:tgz php:web,flavors
USE_PHP=	curl gd gettext iconv imap mbstring mysqli session simplexml xml zlib
IGNORE_WITH_PHP=	81

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	phplist

PLIST_SUB=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
PORTDOCS=	CONTRIBUTING.md COPYING INSTALL PEOPLE README.* TODO UPGRADE VERSION

OPTIONS_DEFINE=	DOCS

PEARDIR?=	${LOCALBASE}/share/pear

post-extract:
	@${MV} ${WRKSRC}/public_html/lists/config/config.php ${WRKSRC}/public_html/lists/config/config.php.sample

# Note: there is file(s) with non-ascii filenames. So it's difficult to add
# such files to pkg-plist. That's why there is find with delete
#
do-install:
	@${FIND} ${WRKSRC}/public_html/ -type f -regex '.*[^!-~].*' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -name '*.md' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -name '.doctrine-project.json' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -name '.editorconfig' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -name '.gitkeep' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -name '.travis.yml' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -name 'composer.json' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -name 'composer.lock' -delete
	@${FIND} ${WRKSRC}/public_html/ -type f -regex '.*/.github/.*' -delete
	@${FIND} ${WRKSRC}/public_html/ -type l -delete
	@${FIND} ${WRKSRC}/public_html/ -type d -empty -delete
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	(cd ${WRKSRC}/public_html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/phplist ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
