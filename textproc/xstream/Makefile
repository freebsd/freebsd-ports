PORTNAME=	xstream
PORTVERSION=	1.4.3
CATEGORIES=	textproc java
MASTER_SITES=	https://nexus.codehaus.org/content/repositories/releases/com/thoughtworks/xstream/xstream-distribution/${PORTVERSION}/
DISTFILES=	${PORTNAME}-distribution-${PORTVERSION}-bin${EXTRACT_SUFX}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Simple library to serialize Java objects to XML

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

OPTIONS_DEFINE=	DOCS

USES=		cpe zip
CPE_VENDOR=	${PORTNAME}_project
USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	${INSTALL_DATA} ${WRKSRC}/lib/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
