# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xstream
PORTVERSION=	1.4.3
CATEGORIES=	textproc java
MASTER_SITES=	https://nexus.codehaus.org/content/repositories/releases/com/thoughtworks/xstream/xstream-distribution/${PORTVERSION}/
DISTFILES=	${PORTNAME}-distribution-${PORTVERSION}-bin${EXTRACT_SUFX}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A simple library to serialize Java objects to XML

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
