# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frost
PORTVERSION=	1.2.0.20090314
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	net-p2p java
MASTER_SITES=	SF/jtc${PORTNAME}/${PORTNAME}/14-Mar-2009
DISTNAME=	${PORTNAME}-14-Mar-2009

MAINTAINER=	peter.thoenen@yahoo.com
COMMENT=	Freenet client that provides messenger and file services

USES=		zip
USE_JAVA=	yes
JAVA_RUN=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

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

DESKTOP_ENTRIES=	"Frost" "Freenet Client" \
			"${JAVASHAREDIR}/${PORTNAME}/jtc.ico" \
			"frost" "P2P;Network;Java;" \
			false

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%DATADIR%%|${DATADIR:S,^${PREFIX}/,,}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
# docs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
# jars
	@${MKDIR} ${STAGEDIR}${PREFIX}/${JAR_DIR}
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${jar} ${STAGEDIR}${PREFIX}/${JAR_DIR}
.endfor
# default boards
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for file in ${DATA_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl}

.include <bsd.port.mk>
