PORTNAME=	seda
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-release-${VERSION_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Architecture for Highly Concurrent Server Applications
WWW=		http://www.eecs.harvard.edu/~mdw/proj/seda/

USES=		java:ant,run

ALL_TARGET=	dist
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

JAVADOC_WRKSRC=	${WRKSRC}/build/javadoc
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

VERSION_DATE=	20020712

PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME:tl}.jar

DOCS_ALL_TARGET=	javadoc

pre-build:
# use our build.xml
	${CP} ${FILESDIR}/build.xml ${WRKSRC}

do-install:
# jar
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/lib/${PORTNAME:tl}.jar \
		${STAGEDIR}${JAVAJARDIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in gnutella-graph.gif index.html nbio.html profile.gif sandstorm.html sandstorm.jpg
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
