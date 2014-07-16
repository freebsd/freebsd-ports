# Created by: babak@farrokhi.net
# $FreeBSD$

PORTNAME=	wikindx
PORTVERSION=	3.8.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}3_8_2
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Bibliographic and quotations/notes management system

USE_PHP=	session mysql xml ctype

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/wikindx3
WWWDIR?=	www/wikindx
ROOTFILES=	config.php index.php rss.php
ROOTDIRS=	attachments core docs files languages modules \
		papers styles templates update
DOCFILES=	CHANGELOG CUSTOMIZATION DISCLAIMER INSTALL \
		LICENSE README README_CMS README_RSS UPGRADE

OPTIONS_DEFINE=	DOCS

pre-install:
	@${ECHO} ${WWWDIR}

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/${WWWDIR}
	(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${STAGEDIR}${PREFIX}/${WWWDIR}/ )
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${WWWDIR}
.for i in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${PREFIX}/${WWWDIR}/ )
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
