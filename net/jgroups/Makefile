# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jgroups
PORTVERSION=	2.12.0
CATEGORIES=	net java
MASTER_SITES=	LOCAL/ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java toolkit for reliable multicast communication

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	jar
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDATA=	*
PORTDOCS=	*

DOCS_ALL_TARGET=javadoc

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/${DISTNAME}.Final.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}-sources.jar \
		${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/README ${STAGEDIR}${DOCSDIR}/
	@(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} javadoc ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
