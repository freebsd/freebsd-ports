PORTNAME=	mucommander
DISTVERSION=	1.5.2-1
CATEGORIES=	x11-fm java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	eric@camachat.org
COMMENT=	Lightweight file manager featuring a Norton Commander style interface
WWW=		https://www.mucommander.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/license.txt

USES=		tar:tgz
USE_JAVA=	yes
JAVA_VERSION=	11+

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	mucommander

WRKSRC=		${WRKDIR}

PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/app && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/app "-name *\.jar"
	cd ${WRKSRC}/bundle && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/bundle "-name *\.jar"
	cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/conf "-name *\.xml"
	${INSTALL_DATA} ${WRKSRC}/mucommander-${DISTVERSION:S/-1//}.jar ${STAGEDIR}${DATADIR}/mucommander.jar
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mucommander ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
