# New ports collection makefile for:	phex
# Date created:				Mon Nov 19 23:48:51 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phex
PORTVERSION=	2.0.0.76
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Java multi platform and spyware free gnutella client

USE_JAVA=	1.4+
USE_PERL5_BUILD=yes
USE_SIZE=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR} \
		JAR_FILE=${JAR_FILE}

JAVAVM=		${LOCALBASE}/bin/java
JAR_DIR=	share/java/jar/${PORTNAME}/
JAR_MANIFEST=	${FILESDIR}/manifest

DOC_FILES=	Phex_other.htm Phex_win.htm
JAR_FILES=	crimson-rt.jar jaxb-api.jar jaxb-libs-rt.jar \
		forms-1.0.4.jar \
		looks-1.2.2.jar \
		jaxb-ri-rt.jar jaxp.jar phex.jar

post-patch:
# remove trailing ^M
	@${PERL} -pi -ne 's!\r\n!\n!' ${WRKSRC}/docs/readme/*
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAVA_VERSION%%|${USE_JAVA}|; \
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
