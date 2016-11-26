# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	trang
PORTVERSION=	2015.11.27
CATEGORIES=	textproc java

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Multi-format schema converter based on RELAX NG

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/trang/copying.txt

USE_GITHUB=	yes
GH_ACCOUNT=	relaxng
GH_PROJECT=	jing-trang
GH_TAGNAME=	1e74846

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_BUILD=	yes
JAVA_RUN=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	convert-to-xsd-talk.html trang.html trang-manual.html

SUB_FILES=	trang.sh
PLIST_FILES=	%%JAVAJARDIR%%/trang.jar bin/trang

.include <bsd.port.options.mk>

do-build:
	(cd ${WRKSRC} && JAVA_HOME=${JAVA_HOME} ./ant)

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/trang.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/trang.sh ${STAGEDIR}${PREFIX}/bin/trang
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/trang/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
