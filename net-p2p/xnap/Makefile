# New ports collection makefile for:	XNap
# Date created:				Mon Nov 19 22:02:27 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XNap
CATEGORIES=	net audio java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTVERSION=	2.5r3
#DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/-pre/:S/.b/-beta/}
DISTNAME=	${PORTNAME:L}-${DISTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A pure java napster client; also, supports OpenNap & giFT (FastTrack)

USE_JAVA=	1.3+
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

JAVAVM=		${LOCALBASE}/bin/java
JAR_DIR=	share/java/jar/${PORTNAME}

DOC_FILES=	AUTHORS COPYING COPYING.LIB NEWS README \
		TODO

post-patch:
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAVA_VERSION%%|${USE_JAVA}|; \
		s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
	@${INSTALL_DATA} ${WRKSRC}/xnap.jar ${PREFIX}/${JAR_DIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
