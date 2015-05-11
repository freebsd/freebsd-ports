# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-net
PORTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	APACHE_COMMONS_SOURCE
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of network protocol implementations for Java

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVAJARDIR}/jakarta-oro.jar:${PORTSDIR}/java/jakarta-oro
RUN_DEPENDS=	${JAVAJARDIR}/jakarta-oro.jar:${PORTSDIR}/java/jakarta-oro

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ARGS=	-cp ${JAVALIBDIR}/junit.jar -Dlibdir=${JAVALIBDIR} -Dnoget=""
MAKE_ENV+=	LANG=C
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if defined(PACKAGE_BUILDING)
ALL_TARGET=	dist
.else
ALL_TARGET=	compile test jar dist
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	LICENSE.txt NOTICE.txt api
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt \
		${STAGEDIR}${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt \
		${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
