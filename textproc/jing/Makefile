# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	jing
PORTVERSION=	20181222
CATEGORIES=	textproc java
MASTER_SITES=	https://github.com/relaxng/jing-trang/releases/download/V${PORTVERSION}/

MAINTAINER=	yasu@utahime.org
COMMENT=	RELAX NG validator in Java

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/copying.html

BROKEN_armv6=		fails to build: modbuild.xml: Java returned: 1
BROKEN_armv7=		fails to build: modbuild.xml: Java returned: 1

USES=		zip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes

PORTDOCS=	*

SUB_FILES=	jing.sh

PLIST_FILES=	bin/jing ${JAVAJARDIR}/jing.jar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jing.sh ${STAGEDIR}${PREFIX}/bin/jing
	${INSTALL_DATA} ${WRKSRC}/bin/jing.jar ${STAGEDIR}${JAVAJARDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
