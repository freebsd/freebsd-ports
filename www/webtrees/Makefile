# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	webtrees
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${PORTVERSION:C/\.[0-9]*$//}/${PORTVERSION}/+download/

MAINTAINER=	fbsd@opal.com
COMMENT=	Online genealogy viewer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		cpe shebangfix zip:infozip
SHEBANG_FILES=	webtrees/library/bombayworks/zendframework1/puppet/scripts/php-build.sh \
		webtrees/library/ezyang/htmlpurifier/maintenance/*.php \
		webtrees/library/ezyang/htmlpurifier/maintenance/*.sh \
		webtrees/library/tecnick.com/tcpdf/tools/tcpdf_addfont.php
USE_PHP=	calendar dom filter gd pcre pdo_mysql session simplexml xml
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message pkg-deinstall

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@exec chown -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
