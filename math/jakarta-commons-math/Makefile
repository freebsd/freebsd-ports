# New ports collection makefile for:	Jakarta Commons Math
# Date created:				January 30th, 2004
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-math
PORTVERSION=	1.0
CATEGORIES=	math java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java library of self-contained mathematics and statistics components

BUILD_DEPENDS=	${JAR_DEPENDS}
RUN_DEPENDS=	${JAR_DEPENDS}

JAR_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVAJARDIR}/commons-discovery.jar:${PORTSDIR}/java/jakarta-commons-discovery

USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_ANT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	jar
MAKE_ARGS=	-Dlibdir=${JAVAJARDIR} -Dnoget=yes
COMMONS_LOGGING_API=	${LOCALBASE}/share/doc/commons-logging/api
.if exists(${COMMONS_LOGGING_API})
MAKE_ARGS+=	-Dcommons-logging.api=${COMMONS_LOGGING_API}
.endif
COMMONS_DISCOVERY_API=	${LOCALBASE}/share/doc/commons-discovery/api
.if exists(${COMMONS_DISCOVERY_API})
MAKE_ARGS+=	-Dcommons-logging.api=${COMMONS_DISCOVERY_API}
.endif

.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
OTHERDOCS=	LICENSE.txt NOTICE.txt
PORTDOCS=	api ${OTHERDOCS}
.endif
JARFILE=	${PORTNAME}-${PORTVERSION}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${DESTJARFILE}

.include <bsd.port.pre.mk>

JDK_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jdk1.? -maxdepth 1 -name api -type d 2>/dev/null || ${TRUE}) | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Djdk.api=${JDK_API}
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/target/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist/docs \
	  && ${FIND} -s api -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} -s api -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
