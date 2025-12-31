PORTNAME=	webtrees
DISTVERSION=	2.2.4
CATEGORIES=	www
MASTER_SITES=	https://github.com/fisharebest/${PORTNAME}/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	22${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Online genealogy viewer (for PHP 8.3+)
WWW=		https://webtrees.net/

LICENSE=	GPLv3+

USES=		cpe php:flavors shebangfix zip
# php pcre extension is required but it's statically linked in default php
USE_PHP=	calendar curl dom filter gd iconv pdo_mysql session xml
IGNORE_WITH_PHP=	82

SHEBANG_FILES=	webtrees/vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php

DOCSDIR=	${PREFIX}/share/doc/webtrees22
WWWDIR=		${PREFIX}/www/webtrees22
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	VERSION_SUFFIX=${PKGNAMESUFFIX}

PORTDOCS=	CONTRIBUTING.md LICENSE.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR} "! -name *\.md" \
		"! -name .DS_Store"
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/${PORTNAME} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
