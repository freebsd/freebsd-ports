# New ports collection makefile for:	phex
# Date created:				Mon Nov 19 23:48:51 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phex
PORTVERSION=	2.2.0.83
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Java multi platform and spyware free gnutella client

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_REINPLACE=	yes
USE_ZIP=	yes
NO_BUILD=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

JAVAVM=		${LOCALBASE}/bin/java
JAR_DIR=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}

DOC_FILES=	Phex_other.htm Phex_win.htm
JAR_FILES=	\
		commons-logging.jar \
		forms-1.0.5.jar \
		jaxb.jar \
		looks-1.3rc.jar \
		phex.jar

PORTDOCS=	${DOC_FILES}

PLIST_FILES+=	bin/${PORTNAME}

.for jar in ${JAR_FILES}
PLIST_FILES+=	%%JAR_DIR%%/${jar}
.endfor

PLIST_DIRS+=	\
		%%JAR_DIR%%

post-patch:
# remove trailing ^M
	@${REINPLACE_CMD} -E \
		-e 's!!!' ${WRKSRC}/docs/readme/*
	@${SED} -e  "s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${jar} ${PREFIX}/${JAR_DIR}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/readme/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

JAR_FILE=	${PORTNAME}.jar

.include <bsd.port.post.mk>
