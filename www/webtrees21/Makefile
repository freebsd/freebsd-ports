PORTNAME=	webtrees
PORTVERSION=	2.1.16
CATEGORIES=	www
MASTER_SITES=	https://github.com/fisharebest/${PORTNAME}/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	21

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Online genealogy viewer (for PHP 7.4-8.2)
WWW=		https://webtrees.net/

LICENSE=	GPLv3+

USES=		cpe php shebangfix zip

USE_PHP=	calendar dom filter gd pdo_mysql session simplexml xml

SHEBANG_FILES=	webtrees/vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php

WWWDIR=		${PREFIX}/www/webtrees${PKGNAMESUFFIX}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	VERSION_SUFFIX=${PKGNAMESUFFIX}

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR} "! -name *\.md"
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
