# New ports collection makefile for:	frost
# Date created:				Fri May 2 05:35:53 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frost
PORTVERSION=	1.2.0.20051020
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	net-p2p java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jtcfrost
DISTNAME=	${PORTNAME}-20-Oct-2005-java${JAVA_VERSION:S/.//}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	File-sharing tool for FreeNet with Usenet like forum support

USE_JAVA=	yes
JAVA_RUN=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

.ifdef(WITH_JDK15)
JAVA_VERSION=	1.5
.else
JAVA_VERSION=	1.4
.endif

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVAVM=		${LOCALBASE}/bin/java
JAR_DIR=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}
JAR_FILE=	frost.jar
JAR_FILES=	frost.jar lib/fecImpl.jar \
		lib/BCastle.jar \
		lib/fec-native.jar \
		lib/genChkImpl.jar lib/xercesImpl.jar \
		lib/mailapi.jar lib/smtp.jar \
		lib/skinlf.jar lib/skinlfFix.jar \
		lib/xml-apis.jar

DOC_FILES=	doc/Frost.tex doc/authors.txt doc/gpl.txt \
		doc/SkinLFLicense.txt \
		doc/hypersonic_lic.txt doc/HISTORY.txt \
		help/faq.txt help/history.txt
PORTDOCS=	${DOC_FILES:C,^.*/,,}

DATA_FILES=	config/boards.xml.default \
		jtc.ico \
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

DESKTOP_ENTRIES=	"Frost" "A Freenet Client" \
			"${JAVASHAREDIR}/${PORTNAME}/jtc.ico" \
			"frost" "Application;P2P;Network;" \
			false

pre-everything::
.ifndef(WITH_JDK15)
	@${ECHO_MSG} '===> Define WITH_JDK15 to use jdk 1.5 instead of jdk 1.4'
.endif

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
