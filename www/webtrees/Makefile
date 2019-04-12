# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	webtrees
PORTVERSION=	1.7.13
CATEGORIES=	www
MASTER_SITES=	http://github.com/fisharebest/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	fbsd@opal.com
COMMENT=	Online genealogy viewer

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		cpe php shebangfix zip
SHEBANG_FILES=	webtrees/vendor/ezyang/htmlpurifier/maintenance/*.php \
		webtrees/vendor/ezyang/htmlpurifier/maintenance/*.sh \
		webtrees/vendor/swiftmailer/swiftmailer/lib/swiftmailer_generate_mimes_config.php \
		webtrees/vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php
USE_PHP=	calendar dom filter gd json pcre pdo_mysql session simplexml xml
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message pkg-deinstall

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec chown -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
