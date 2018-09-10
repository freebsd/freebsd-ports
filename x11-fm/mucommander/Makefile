# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	mucommander
DISTVERSION=	0_9_0
CATEGORIES=	x11-fm java
MASTER_SITES=	http://www.mucommander.com/download/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Lightweight file manager featuring a Norton Commander style interface

LICENSE=	GPLv3

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	bin/mucommander %%DATADIR%%/mucommander.jar %%DATADIR%%/license.txt
SUB_FILES=	mucommander

PORTDOCS=	readme.txt

WRKSRC=		${WRKDIR}/muCommander-${PORTVERSION:S/./_/g}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mucommander.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mucommander ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
