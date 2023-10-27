PORTNAME=	xincluder
PORTVERSION=	1.0.d11
PORTREVISION=	7
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/languages/java/javafaq/
DISTNAME=	${PORTNAME}-1.0d11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java-based XInclude processors
WWW=		https://xincluder.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

BUILD_DEPENDS=	${JAVALIBDIR}/jdom.jar:java/jdom \
		${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j
RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:java/jdom \
		${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j

USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	clean jar
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

SUFFIXES=	-sax -dom -jdom
PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar bin/xincluder ${SUFFIXES:S,^,bin/xincluder,}
PORTDOCS=	apidoc index.html
SUB_FILES=	xincluder.sh

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s,\./lib/jdom-1.0b9rc.jar,${JAVAJARDIR}/jdom.jar," \
		-e "s,\./lib/xercesImpl-2.0.2.jar,${JAVAJARDIR}/xercesImpl.jar," \
		-e "s,\./lib/xmlParserAPIs-2.0.2.jar,${JAVAJARDIR}/xml-apis.jar," \
		-e 's,<javac srcdir,<javac source="1.8" target="1.8" debug="true" \
			includeantruntime="false" srcdir,' \
		${WRKSRC}/build.xml

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/xincluder.sh ${STAGEDIR}${PREFIX}/bin/xincluder
.for suffix in ${SUFFIXES}
	${LN} -s xincluder ${STAGEDIR}${PREFIX}/bin/xincluder${suffix}
.endfor

do-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
