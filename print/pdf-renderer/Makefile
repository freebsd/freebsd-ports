# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdf-renderer
PORTVERSION=	0.9.1
PORTEPOCH=	1
CATEGORIES=	print java
MASTER_SITES=	http://java.net/downloads/${PORTNAME}/
DISTNAME=	PDFRenderer-full-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A 100% Java PDF renderer and viewer

LICENSE=	LGPL21

USES=		zip
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/PDFRenderer.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist && ${FIND} javadoc \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
