# New ports collection makefile for:	frost
# Date created:				Fri May 2 05:35:53 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frost
PORTVERSION=	1.2.0.20050203
PORTEPOCH=	2
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jtcfrost
DISTNAME=	${PORTNAME}-03-Feb-2005-java14

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	File-sharing tool for FreeNet with Usenet like forum support

USE_JAVA=	yes
JAVA_VERSION=	1.4
USE_ZIP=	yes
NO_BUILD=	yes
#WRKSRC=		${WRKDIR}/${PORTNAME}
NO_WRKSUBDIR=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

VERSION_DATE=	090603

JAVAVM=		${LOCALBASE}/bin/java
JAR_DIR=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}
JAR_FILE=	frost.jar
JAR_FILES=	frost.jar lib/fecImpl.jar \
		lib/BCastle.jar \
		lib/fec-native.jar \
		lib/genChkImpl.jar lib/xercesImpl.jar \
		lib/jocache.jar \
		lib/mailapi.jar lib/smtp.jar \
		lib/skinlf.jar lib/skinlfFix.jar \
		lib/xml-apis.jar

DOC_FILES=	doc/Frost.tex doc/authors.txt doc/gpl.txt \
		doc/SkinLFLicense.txt \
		doc/hypersonic_lic.txt doc/HISTORY.txt \
		help/faq.txt help/history.txt
PORTDOCS=	${DOC_FILES:C,^.*/,,}

DATA_FILES=	config/boards.xml.default \
		themes/aquathemepack.zip \
		themes/themepack.zip

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
