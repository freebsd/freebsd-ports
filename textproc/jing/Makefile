# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	jing
PORTVERSION=	2017.09.14
CATEGORIES=	textproc java

MAINTAINER=	yasu@utahime.org
COMMENT=	RELAX NG validator in Java

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/copying.txt

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

PORTDOCS=	*

SUB_FILES=	jing.sh

PLIST_FILES=	bin/jing ${JAVAJARDIR}/jing.jar

do-build:
	(cd ${WRKSRC} && JAVA_HOME=${JAVA_HOME} ./ant)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jing.sh ${STAGEDIR}${PREFIX}/bin/jing
	${INSTALL_DATA} ${WRKSRC}/build/jing.jar ${STAGEDIR}${JAVAJARDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
