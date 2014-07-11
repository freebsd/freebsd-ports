# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	seda
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	net java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-release-${VERSION_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Architecture for Highly Concurrent Server Applications

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	dist

OPTIONS_DEFINE=	DOCS

JAVADOC_WRKSRC=	${WRKSRC}/build/javadoc
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

VERSION_DATE=	20020712

DOC_FILES=	\
		gnutella-graph.gif \
		index.html \
		nbio.html \
		profile.gif \
		sandstorm.html \
		sandstorm.jpg
PORTDOCS=	${DOC_FILES} \
		javadoc

PLIST_FILES=	\
		%%JAVAJARDIR%%/${PORTNAME:tl}.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

pre-build:
# use our build.xml
	${CP} ${FILESDIR}/build.xml ${WRKSRC}

do-install:
# jar
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${PORTNAME:tl}.jar \
		${STAGEDIR}${JAVAJARDIR}/
# docs
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${STAGEDIR}${DOCSDIR}
. endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/javadoc
# line taken from textproc/xerces-j maintained by hq@FreeBSD.org
	cd ${JAVADOC_WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/javadoc/{}" \; && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DOCSDIR}/javadoc/{}" \;
.endif

.include <bsd.port.mk>
