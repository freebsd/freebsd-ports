# New ports collection makefile for:	frost
# Date created:				Fri May 2 05:35:53 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frost
PORTVERSION=	1.2.0.6
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jtcfrost
DISTNAME=	${PORTNAME}-wot-071203-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	File-sharing tool for FreeNet with Usenet like forum support

USE_JAVA=	1.4+
USE_ZIP=	yes
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	JAR_DIR=${JAR_DIR}

JAVAVM=		${LOCALBASE}/bin/javavm
SHARE_DIR=	share/${PORTNAME}
JAR_DIR=	share/java/jar/${PORTNAME}
JAR_FILE=	frost.jar
JAR_FILES=	frost/frost.jar frost/lib/fecImpl.jar \
		frost/lib/genChkImpl.jar frost/lib/xercesImpl.jar \
		frost/lib/xml-apis.jar frost/lib/xmlParserAPIs.jar \
		convert/converter.jar

DOC_FILES=	doc/Frost.tex doc/authors.txt doc/gpl.txt \
		help/faq.txt help/history.txt

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%SHARE_DIR%%|${SHARE_DIR}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAR_DIR%%|${JAR_DIR}|;" \
		${FILESDIR}/wrapper-convert.sh > ${WRKDIR}/wrapper-convert.sh

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
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper-convert.sh ${PREFIX}/bin/frost-convert

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s,%%PREFIX%%,${PREFIX},g"

.include <bsd.port.mk>
