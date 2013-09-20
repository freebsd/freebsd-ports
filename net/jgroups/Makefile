# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jgroups
PORTVERSION=	2.12.0
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java toolkit for reliable multicast communication

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

PORTDATA=	*
PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/${DISTNAME}.Final.jar \
		${JAVAJARDIR}/${PORTNAME}.jar
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}-sources.jar \
		${DATADIR}/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/dist/README ${DOCSDIR}/
	@(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} javadoc ${DOCSDIR})
.endif

.include <bsd.port.mk>
