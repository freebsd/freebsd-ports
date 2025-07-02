PORTNAME=	webtrees
DISTVERSION=	2.1.22
CATEGORIES=	www
MASTER_SITES=	https://github.com/fisharebest/${PORTNAME}/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	21${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Online genealogy viewer (for PHP 7.4-8.2)
WWW=		https://webtrees.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/${PORTNAME}/LICENSE.md

IGNORE_WITH_PHP=	83 84 85
USES=		cpe php shebangfix zip
# php pcre extension is required but it's statically linked in default php
USE_PHP=	calendar curl dom filter gd iconv pdo_mysql session xml

SHEBANG_FILES=	webtrees/vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php

CONFLICTS=	webtrees20-2.0*

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-deinstall pkg-message

PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR} "! -name *\.md"
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/${PORTNAME} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
