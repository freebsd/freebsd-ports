# Created by: ijliao
# $FreeBSD$

PORTNAME=	jcifs
PORTVERSION=	1.3.19
PORTEPOCH=	1
CATEGORIES=	net java
MASTER_SITES=	http://jcifs.samba.org/src/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java CIFS Client Library

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		tar:tgz
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
NO_ARCH=	yes
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
