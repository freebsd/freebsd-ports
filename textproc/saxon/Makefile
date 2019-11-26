# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	saxon
PORTVERSION=	6.5.5
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	SF/${PORTNAME}/saxon6/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSLT 1.0 processor for Java

LICENSE=	MPL10

USES=		zip
USE_JAVA=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

CONFLICTS=	saxon-devel-8.*

JARFILES=	saxon-jdom.jar saxon.jar
PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,} bin/saxon
PORTDOCS=	api api-guide.html changes.html conditions.html \
		conformance.html dtdgen.html expressions.html \
		extensibility.html extensions.html index.html \
		instant.html limitations.html patterns.html samples.html \
		saxon-style.css using-xsl.html xsl-elements.html

SUB_LIST=	SAXON_JARS="${JARFILES:S,^,${JAVAJARDIR}/,}"
SUB_FILES=	saxon.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
.for JARFILE in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/saxon.sh ${STAGEDIR}${PREFIX}/bin/saxon

do-install-DOCS-on:
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
