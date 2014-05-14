# Created by: ijliao
# $FreeBSD$

PORTNAME=	jcifs
PORTVERSION=	1.3.17
PORTEPOCH=	1
CATEGORIES=	net java
MASTER_SITES=	http://jcifs.samba.org/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	The Java CIFS Client Library

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_JAVA=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/examples && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/examples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/{} \;

.include <bsd.port.mk>
