# Created by: Palle Girgensohn
# $FreeBSD$

PORTNAME=	crimson
PORTVERSION=	1.1.3
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/crimson/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implements the Java API for XML Processing (JAXP)

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
JAVAVM?=	${LOCALBASE}/bin/javavm

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message
PLIST_FILES=	share/java/classes/crimson.jar
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/java/classes
	${INSTALL_DATA} ${INSTALL_WRKSRC}/crimson.jar ${STAGEDIR}${PREFIX}/share/java/classes

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC} && ${INSTALL_DATA} README.html ChangeLog ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
