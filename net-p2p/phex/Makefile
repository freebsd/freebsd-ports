# New ports collection makefile for:	phex
# Date created:				Mon Nov 19 23:48:51 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phex
PORTVERSION=	0.7.3
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}_j2se1.3

MAINTAINER=	lioux@FreeBSD.org

USE_JAVA=	1.3+
USE_ZIP=	yes
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR} \
		JAR_FILE=${JAR_FILE}

JAVAVM=		${LOCALBASE}/bin/javavm
JAR_DIR=	share/java/jar/${PORTNAME}/
JAR_MANIFEST=	${FILESDIR}/manifest

DOC_FILES=      COPYING License-RI.html License-W3C.html changelog.txt \
		contributors.txt readme-Furi.txt readme-developers.txt \
		GPL.txt \
		readme.txt
JAR_FILES=	crimson.jar jaxp.jar phex.jar xalan.jar

post-patch:
# remove trailing ^M
	@${PERL} -pi -ne 's!\r\n!\n!' ${WRKSRC}/readme/*
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAR_FILE%%|${JAR_FILE}|; \
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
	@${INSTALL_DATA} ${WRKSRC}/readme/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

JAR_FILE=	${PORTNAME}.jar

.include <bsd.port.post.mk>
