# New ports collection makefile for:	Jakarta Commons Digester
# Date created:				November 28, 2004
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-digester
PORTVERSION=	1.7
CATEGORIES=	textproc java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	XML-to-Java-object mapping utility package

BUILD_DEPENDS=	${JAR_DEPENDS}
RUN_DEPENDS=	${JAR_DEPENDS}

USE_JAVA=	yes
JAVA_VERSION=	1.2+

USE_ANT=	yes
MAKE_ARGS=	-Dcommons-beanutils.api=${COMMONS_BEANUTILS_API} \
		-Dcommons-collections.api=${COMMONS_COLLECTIONS_API} \
		-Dcommons-logging.api=${COMMONS_LOGGING_API} \
		-Dcommons-beanutils.jar=${JAVALIBDIR}/commons-beanutils.jar \
		-Dcommons-collections.jar=${JAVALIBDIR}/commons-collections.jar \
		-Dcommons-logging.jar=${JAVALIBDIR}/commons-logging.jar
ALL_TARGET=	dist

JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
.if !defined(NOPORTDOCS)
OTHERDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt
PORTDOCS=	api ${OTHERDOCS}
.endif

COMMONS_BEANUTILS_API=	${LOCALBASE}/share/doc/commons-beanutils
COMMONS_COLLECTIONS_API=${LOCALBASE}/share/doc/commons-collections/apidocs
COMMONS_LOGGING_API=	${LOCALBASE}/share/doc/commons-logging/api

.include <bsd.port.pre.mk>

JAR_DEPENDS=	${JAVALIBDIR}/commons-beanutils.jar:${PORTSDIR}/java/jakarta-commons-beanutils \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections
.if ${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/} != "1.4"
JAR_DEPENDS+=	${JAVALIBDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j
.endif

do-configure:
	@if [ -d "${COMMONS_BEANUTILS_API}" ] ; \
	then \
	  ${REINPLACE_CMD} -e 's,http://jakarta.apache.org/commons/beanutils/api/,${COMMONS_BEANUTILS_API},' ${WRKSRC}/build.xml ; \
	fi
	@if [ -d "${COMMONS_COLLECTIONS_API}" ] ; \
	then \
	  ${REINPLACE_CMD} -e 's,http://jakarta.apache.org/commons/collections/api/,${COMMONS_COLLECTIONS_API},' ${WRKSRC}/build.xml ; \
	fi
	@if [ -d "${COMMONS_LOGGING_API}" ] ; \
	then \
	  ${REINPLACE_CMD} -e 's,http://jakarta.apache.org/commons/logging/api/,${COMMONS_LOGGING_API},' ${WRKSRC}/build.xml ; \
	fi

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${JARFILE} ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/dist/docs \
	  && ${FIND} api -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} api -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/dist/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
