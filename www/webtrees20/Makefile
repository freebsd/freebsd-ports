# Created by: Andre Rikkert de Koe - ARK-ICT <andre@ark-ict.nl>
# $FreeBSD$

PORTNAME=	webtrees20
PORTVERSION=	2.0.12
CATEGORIES=	www
MASTER_SITES=	http://github.com/fisharebest/webtrees/releases/download/${PORTVERSION}/ \
		https://freebsd.ark-ict.nl/ports/
DISTNAME=	webtrees-${PORTVERSION}

MAINTAINER=	andre@ark-ict.nl
COMMENT=	Online genealogy viewer

LICENSE=	LGPL3

USES=		cpe php shebangfix zip
SHEBANG_FILES=	webtrees20/vendor/swiftmailer/swiftmailer/lib/swiftmailer_generate_mimes_config.php \
		webtrees20/vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USE_PHP=	calendar dom filter gd json pcre pdo_mysql session simplexml xml
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message pkg-deinstall

WWWDIR=		${PREFIX}/www/webtrees20

post-extract:
	@${MV} ${WRKSRC}/webtrees ${WRKSRC}/${PORTNAME}

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
