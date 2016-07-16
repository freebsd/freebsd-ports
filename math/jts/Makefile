# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	jts
PORTVERSION=	1.14
CATEGORIES=	math databases java
MASTER_SITES=	SF/${PORTNAME}-topo-suite/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JTS Topology Suite

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:java/jdom \
		${JAVALIBDIR}/junit.jar:java/junit \
		${JAVALIBDIR}/xml-apis.jar:textproc/xerces-j

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
NO_WRKSUBDIR=	yes

VER=		${PORTVERSION:tl}
JARFILES=	JTS_Test jts-${VER} jtsio-${VER}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
.for jar in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${jar}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${jar:S|-${VER}||}.jar
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

do-test:
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|;	\
			s|%%JAVALIBDIR%%|${JAVALIBDIR}|;\
			s|%%JAVA%%|${JAVA}|'		\
		${FILESDIR}/testJTS.sh.in > ${WRKSRC}/testJTS.sh
	(cd ${WRKSRC} && ${SH} ./testJTS.sh )

.include <bsd.port.mk>
