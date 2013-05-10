# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	dtdinst
PORTVERSION=	2009.11.11
CATEGORIES=	textproc java
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	jing-trang
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts DTDs to XML instance, in a specific or RELAX NG format

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/copying.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_BUILD=	yes

USE_ZIP=	yes
USE_JAVA=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	%%JAVAJARDIR%%/dtdinst.jar share/xsl/dtdinst/dtdinst2rng.xsl
PLIST_DIRS=	share/xsl/dtdinst
PLIST_DIRSTRY=	share/xsl

.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} *.jar ${JAVAJARDIR})
	@${MKDIR} ${PREFIX}/share/xsl/dtdinst
	(cd ${WRKSRC} && ${INSTALL_DATA} *.xsl ${PREFIX}/share/xsl/dtdinst)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in dtdinst.rnc.txt dtdinst.rng index.html teixml.dtd.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${INSTALL_DATA} * ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
