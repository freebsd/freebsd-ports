# New ports collection makefile for:	wikindx
# Date created:		23 Dec 2005
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	wikindx
PORTVERSION=	3.2.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wikindx
DISTNAME=	wikindx3_2_4

MAINTAINER=	babak@farrokhi.net
COMMENT=	Bibliographic and quotations/notes management system

USE_PHP=	session mysql

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/wikindx3
WIKINDX?=	www/data-dist/wikindx
PLIST_SUB+=	WIKINDX=${WIKINDX}
ROOTFILES=	config.php index.php rss.php
ROOTDIRS=	attachments core docs files languages modules \
		papers styles templates update
DOCFILES=	CHANGELOG CUSTOMIZATION DISCLAIMER INSTALL \
		LICENSE README README_RSS UPDATEWIKINDX

do-install:
	-${MKDIR} ${PREFIX}/${WIKINDX}
	(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${WIKINDX}/ )
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${WIKINDX}
.for i in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${CP} -R ${i} ${PREFIX}/${WIKINDX}/ )
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
