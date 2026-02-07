PORTNAME=	pdf-renderer
PORTVERSION=	0.9.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	print java
MASTER_SITES=	LOCAL/ale
DISTNAME=	PDFRenderer-full-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	100% Java PDF renderer and viewer

LICENSE=	LGPL21

USES=		dos2unix java:ant,run zip
NO_WRKSUBDIR=	yes

ALL_TARGET=	jar

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
DOS2UNIX_FILES=	swinglabs-build-impl.xml

DOCS_ALL_TARGET=	javadoc

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/PDFRenderer.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/dist && ${FIND} javadoc \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"

.include <bsd.port.mk>
