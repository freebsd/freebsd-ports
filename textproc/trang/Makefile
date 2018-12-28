# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	trang
PORTVERSION=	20181222
CATEGORIES=	textproc java
MASTER_SITES=	https://github.com/relaxng/jing-trang/releases/download/V${PORTVERSION}/

MAINTAINER=	yasu@utahime.org
COMMENT=	Multi-format schema converter based on RELAX NG

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/copying.txt

BROKEN_armv6=		fails to build: modbuild.xml: Java returned: 1
BROKEN_armv7=		fails to build: modbuild.xml: Java returned: 1

USES=		zip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes

PORTDOCS=	trang-manual.html

SUB_FILES=	trang.sh

PLIST_FILES=	bin/trang ${JAVAJARDIR}/trang.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/trang.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/trang.sh ${STAGEDIR}${PREFIX}/bin/trang

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
