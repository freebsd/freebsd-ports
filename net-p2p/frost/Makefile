# New ports collection makefile for:	frost
# Date created:				Fri May 2 05:35:53 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frost
PORTVERSION=	1.2
CATEGORIES=	net java
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	jtcfrost
MASTER_SITES=	http://jtcfrost.sourceforge.net/
DISTNAME=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	File-sharing tool for FreeNet with Usenet like forum support

USE_JAVA=	1.4+
USE_ZIP=	yes
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	JAR_DIR=${JAR_DIR}

JAVAVM=		${LOCALBASE}/bin/javavm
JAR_DIR=	share/java/jar/${PORTNAME}
JAR_FILE=	frost.jar

DOC_FILES=	doc/Frost.tex doc/authors.txt doc/gpl.txt doc/notes.txt \
		help/faq.txt help/history.txt

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
# jar
	@${MKDIR} ${PREFIX}/${JAR_DIR}
	@${INSTALL_DATA} ${WRKSRC}/${JAR_FILE} ${PREFIX}/${JAR_DIR}
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}

.include <bsd.port.mk>
