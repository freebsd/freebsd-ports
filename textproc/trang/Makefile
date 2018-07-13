# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	trang
PORTVERSION=	2017.09.14
CATEGORIES=	textproc java

MAINTAINER=	yasu@utahime.org
COMMENT=	Multi-format schema converter based on RELAX NG

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/trang/copying.txt

BROKEN_armv6=		fails to build: modbuild.xml: Java returned: 1
BROKEN_armv7=		fails to build: modbuild.xml: Java returned: 1

USE_GITHUB=	yes
GH_ACCOUNT=	relaxng
GH_PROJECT=	jing-trang
GH_TAGNAME=	bf4bafa

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_BUILD=	yes
JAVA_RUN=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	convert-to-xsd-talk.html trang.html trang-manual.html

SUB_FILES=	trang.sh

PLIST_FILES=	${JAVAJARDIR}/trang.jar bin/trang

do-build:
	(cd ${WRKSRC} && JAVA_HOME=${JAVA_HOME} ./ant)

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/trang.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/trang.sh ${STAGEDIR}${PREFIX}/bin/trang

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/trang/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
