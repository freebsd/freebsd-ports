# Created by: Palle Girgensohn
# $FreeBSD$

PORTNAME=	crimson
PORTVERSION=	1.1.3
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/crimson/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	girgen@partitur.se
COMMENT=	Implements the Java API for XML Processing (JAXP)

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
JAVAVM?=	${LOCALBASE}/bin/javavm

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

SUB_FILES=	pkg-message
PLIST_FILES=	share/java/classes/crimson.jar
PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/java/classes
	${INSTALL_DATA} ${INSTALL_WRKSRC}/crimson.jar ${STAGEDIR}${PREFIX}/share/java/classes
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${INSTALL_WRKSRC} && ${INSTALL_DATA} README.html ChangeLog ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
