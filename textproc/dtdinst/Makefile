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

USES=		zip
USE_JAVA=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	%%JAVAJARDIR%%/dtdinst.jar share/xsl/dtdinst/dtdinst2rng.xsl
PLIST_DIRS=	share/xsl/dtdinst
PLIST_DIRSTRY=	share/xsl

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.jar ${STAGEDIR}${JAVAJARDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsl/dtdinst
	(cd ${WRKSRC} && ${INSTALL_DATA} *.xsl ${STAGEDIR}${PREFIX}/share/xsl/dtdinst)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in dtdinst.rnc.txt dtdinst.rng index.html teixml.dtd.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
