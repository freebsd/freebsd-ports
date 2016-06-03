# Created by: babak@farrokhi.net
# $FreeBSD$

PORTNAME=	wikindx
PORTVERSION=	3.8.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}3_8_2
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bibliographic and quotations/notes management system

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USE_PHP=	session mysql xml ctype

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/wikindx3
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
ROOTFILES=	config.php index.php rss.php
ROOTDIRS=	attachments core docs files languages modules \
		papers styles templates update
DOCFILES=	CHANGELOG CUSTOMIZATION DISCLAIMER INSTALL \
		LICENSE README README_CMS README_RSS UPGRADE

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${STAGEDIR}${WWWDIR}/ )
.for i in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}/ )
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
