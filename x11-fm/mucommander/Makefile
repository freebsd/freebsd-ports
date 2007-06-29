# New ports collection makefile for:	mucommander
# Date created:		2007-06-24
# Whom:			Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	mucommander
DISTVERSION=	0.8beta3
CATEGORIES=	x11-fm java
MASTER_SITES=	http://www.mucommander.com/download/
DISTNAME=	${PORTNAME}-0_8_beta3

MAINTAINER=	lars.engels@0x20.net
COMMENT=	Lightweight file manager featuring a Norton Commander style interface

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	bin/mucommander %%DATADIR%%/mucommander.jar %%DATADIR%%/license.txt
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	mucommander pkg-message

PORTDOCS=	readme.txt

WRKSRC=		${WRKDIR}/muCommander-0_8_beta3

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mucommander.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mucommander ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
