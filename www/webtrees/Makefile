# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	webtrees
PORTVERSION=	1.6.2
CATEGORIES=	www
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${PORTVERSION:C/\.[0-9]*$//}/${PORTVERSION}/+download/

MAINTAINER=	fbsd@opal.com
COMMENT=	Online genealogy viewer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		zip:infozip
USE_PHP=	calendar dom gd pcre session xml pdo_mysql
NO_BUILD=	yes

SUB_FILES=	pkg-message pkg-deinstall

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_BIN} . ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -ne 's,^${PORTNAME}/,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} \
		'@exec chown -R ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/data' \
		>> ${TMPPLIST}
	@(cd ${WRKSRC}/${PORTNAME}; ${FIND} . -type d) | ${SORT} -r | \
		${SED} -ne 's,^${PORTNAME}/,@dirrm ${WWWDIR_REL}/,p' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
