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

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/copying.txt

BROKEN=		Unfetchable (google code has gone away)

NO_BUILD=	yes
NO_ARCH=	yes

USES=		zip
USE_JAVA=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	%%JAVAJARDIR%%/dtdinst.jar share/xsl/dtdinst/dtdinst2rng.xsl

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.jar ${STAGEDIR}${JAVAJARDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsl/dtdinst
	(cd ${WRKSRC} && ${INSTALL_DATA} *.xsl ${STAGEDIR}${PREFIX}/share/xsl/dtdinst)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in dtdinst.rnc.txt dtdinst.rng index.html teixml.dtd.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
