# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	elgg
PORTVERSION=	1.8.0.1
CATEGORIES=	www
MASTER_SITES=	http://elgg.org/download/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Blogging and social networking platform

LICENSE=	GPLv2

USE_PHP=	mysql gd json soap dom xml
USES=		gettext zip

NO_BUILD=	yes
SUB_FILES=	pkg-message
ELGGDATADIR=	${WWWDIR}data

.include <bsd.port.pre.mk>
do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}' \
		>> ${TMPPLIST}

	@${INSTALL} -d ${STAGEDIR}${ELGGDATADIR}
	@${CHMOD} 777 ${STAGEDIR}${ELGGDATADIR}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${STAGEDIR}${ELGGDATADIR}' \
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
