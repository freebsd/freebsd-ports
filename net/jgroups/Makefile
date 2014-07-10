# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jgroups
PORTVERSION=	2.12.0
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java toolkit for reliable multicast communication

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	jar

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDATA=	*
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/${DISTNAME}.Final.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}-sources.jar \
		${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/dist/README ${STAGEDIR}${DOCSDIR}/
	@(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} javadoc ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
