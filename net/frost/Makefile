# New ports collection makefile for:	frost
# Date created:				Fri May 2 05:35:53 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frost
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jtcfrost
DISTNAME=	${PORTNAME}-wot-${VERSION_DATE}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	File-sharing tool for FreeNet with Usenet like forum support

USE_JAVA=	1.4+
USE_SIZE=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
#WRKSRC=		${WRKDIR}/${PORTNAME}
NO_WRKSUBDIR=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

VERSION_DATE=	090603

JAVAVM=		${LOCALBASE}/bin/javavm
SHARE_DIR=	share/${PORTNAME}
JAR_DIR=	share/java/jar/${PORTNAME}
JAR_FILE=	frost.jar
JAR_FILES=	frost.jar lib/fecImpl.jar \
		lib/genChkImpl.jar lib/xercesImpl.jar \
		lib/xml-apis.jar lib/xmlParserAPIs.jar

DOC_FILES=	doc/Frost.tex doc/authors.txt doc/gpl.txt \
		help/faq.txt help/history.txt

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%SHARE_DIR%%|${SHARE_DIR}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
# jars
	@${MKDIR} ${PREFIX}/${JAR_DIR}
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKDIR}/${jar} ${PREFIX}/${JAR_DIR}
.endfor
# default boards
	@${MKDIR} ${PREFIX}/${SHARE_DIR}
	@${INSTALL_DATA} ${WRKSRC}/config/boards.xml.default \
		${PREFIX}/${SHARE_DIR}
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}

.include <bsd.port.mk>
