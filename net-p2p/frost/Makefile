# New ports collection makefile for:	frost
# Date created:				Fri May 2 05:35:53 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frost
PORTVERSION=	1.2.0.20080304
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	net-p2p java
MASTER_SITES=	SF/jtc${PORTNAME}/${PORTNAME}/04-Mar-2008
DISTNAME=	${PORTNAME}-04-Mar-2008

MAINTAINER=	peter.thoenen@yahoo.com
COMMENT=	Frost is a Freenet client that provides messenger and file services

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_RUN=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVAVM=		${LOCALBASE}/bin/java
JAR_DIR=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}
JAR_FILE=	frost.jar
JAR_FILES=	frost.jar lib/fecImpl.jar \
		lib/BCastle.jar lib/datechooser.jar \
		lib/fec-native.jar \
		lib/genChkImpl.jar lib/gnu-regexp-1.1.4.jar \
		lib/xercesImpl.jar \
		lib/joda-time.jar \
		lib/perst15.jar \
		lib/xml-apis.jar

DOC_FILES=	doc/Frost.tex doc/authors.txt doc/gpl.txt \
		doc/SkinLFLicense.txt
PORTDOCS=	${DOC_FILES:C,^.*/,,}

DATA_FILES=	config/boards.xml.default07 \
		jtc.ico \

PLIST_FILES=	bin/${PORTNAME}

.for jar in ${JAR_FILES:C,^.*/,,}
PLIST_FILES+=	%%JAR_DIR%%/${jar}
.endfor

.for file in ${DATA_FILES:C,^.*/,,}
PLIST_FILES+=	%%DATADIR%%/${file}
.endfor

PLIST_DIRS+=	\
		%%JAR_DIR%% \
		%%DATADIR%%

DESKTOP_ENTRIES=	"Frost" "A Freenet Client" \
			"${JAVASHAREDIR}/${PORTNAME}/jtc.ico" \
			"frost" "Application;P2P;Network;" \
			false

pre-everything::

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%DATADIR%%|${DATADIR:S,^${PREFIX}/,,}|" \
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
	@${MKDIR} ${DATADIR}
.for file in ${DATA_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}

.include <bsd.port.mk>
