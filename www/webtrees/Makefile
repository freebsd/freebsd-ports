# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	webtrees
PORTVERSION=	1.7.18
CATEGORIES=	www
MASTER_SITES=	http://github.com/fisharebest/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	fbsd@opal.com
COMMENT=	Online genealogy viewer (for PHP 5.3-7.3)

LICENSE=	GPLv3+

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
SUB_LIST=	VERSION_SUFFIX=${PKGNAMESUFFIX}

post-patch: .SILENT
	${RM} -r ${WRKSRC}/webtrees/vendor/michelf/php-markdown/test
	${RM} ${WRKSRC}/webtrees/vendor/michelf/php-markdown/.editorconfig
	${RM} ${WRKSRC}/webtrees/vendor/michelf/php-markdown/.scrutinizer.yml
	${RM} ${WRKSRC}/webtrees/vendor/michelf/php-markdown/phpunit.xml.dist

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
