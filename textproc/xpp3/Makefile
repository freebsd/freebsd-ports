# New ports collection makefile for:	xpp3
# Date created:		2004-04-02
# Whom:			Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	xpp3
PORTVERSION=	1.1.3.4.M
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://www.extreme.indiana.edu/dist/java-repository/xpp3/distributions/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	hq@FreeBSD.org
COMMENT=	XML Pull Parser 3rd Edition (XPP3)

BUILD_DEPENDS=	${JAVAJARDIR}/xmlpull.jar:${PORTSDIR}/textproc/xmlpull
RUN_DEPENDS=	${JAVAJARDIR}/xmlpull.jar:${PORTSDIR}/textproc/xmlpull

USE_JAVA=	yes
JAVA_VERSION=	1.3+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ANT=	yes
ALL_TARGET=	jar
MAKE_ARGS=	-Djavadoc_packages=org.xmlpull.mxp1
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
PORTDOCS=	api_impl ABOUT.txt THANKS.txt TODO.html build.txt changes.html faq.html
.endif
JARFILE=	${PORTNAME}-${PORTVERSION}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}

.include <bsd.port.pre.mk>

JDK_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jdk1.? -maxdepth 1 -name api -type d 2>/dev/null || ${TRUE}) | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Djdk.api=${JDK_API}
.endif

XMLPULL_API!=	(${FIND} -s ${LOCALBASE}/share/doc/xmlpull -maxdepth 1 -name api -type d 2>/dev/null || ${TRUE}) | ${TAIL} -n 1
.if ${XMLPULL_API} != ""
MAKE_ARGS+=	-Dxmlpull.api=${XMLPULL_API}
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
