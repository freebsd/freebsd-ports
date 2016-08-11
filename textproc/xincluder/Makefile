# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xincluder
PORTVERSION=	1.0.d11
PORTREVISION=	5
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/languages/java/javafaq/
DISTNAME=	${PORTNAME}-1.0d11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java-based XInclude processors

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:java/jdom \
		${JAVALIBDIR}/xercesImpl.jar:textproc/xerces-j

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

SUFFIXES=	-sax -dom -jdom
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar bin/xincluder ${SUFFIXES:S,^,bin/xincluder,}
PORTDOCS=	apidoc index.html
SUB_FILES=	xincluder.sh

OPTIONS_DEFINE=	DOCS

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
