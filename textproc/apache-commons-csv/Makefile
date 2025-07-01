PORTNAME=	commons-csv
DISTVERSION=	1.14.0
CATEGORIES=	textproc java devel
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	mclay@astate.edu
COMMENT=	Java support for Comma Separated Value format
WWW=		https://commons.apache.org/proper/commons-csv/

LICENSE=	APACHE20

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

JARFILE=	${PORTNAME}.jar
PLIST_FILES=	${JAVAJARDIR}/${JARFILE}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

OTHERDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${DISTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/apidocs \
	  && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
