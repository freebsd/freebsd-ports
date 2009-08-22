# New ports collection makefile for:	wikindx
# Date created:		23 Dec 2005
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

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

pre-install:
	@${ECHO} ${WWWDIR}

do-install:
	-${MKDIR} ${PREFIX}/${WWWDIR}
	(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${WWWDIR}/ )
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${WWWDIR}
.for i in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${PREFIX}/${WWWDIR}/ )
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
