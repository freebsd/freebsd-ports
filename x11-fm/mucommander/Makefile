PORTNAME=	mucommander
DISTVERSION=	1.1.0-1
CATEGORIES=	x11-fm java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight file manager featuring a Norton Commander style interface
WWW=		https://www.mucommander.com

LICENSE=	GPLv3

USES=		tar:tgz
USE_JAVA=	yes
JAVA_VERSION=	11+

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	mucommander

WRKSRC=		${WRKDIR}

PLIST_FILES=	${DATADIR}/license.txt \
		${DATADIR}/mucommander.jar \
		bin/mucommander
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mucommander-${DISTVERSION:S/-1//}.jar ${STAGEDIR}${DATADIR}/mucommander.jar
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mucommander ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
