# Created by: Joshua Goodall <joshua@roughtrade.net>
# $FreeBSD$

PORTNAME=	spread
PORTVERSION=	3.17.3
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	http://www.cnds.jhu.edu/download/noformdown/
PKGNAMESUFFIX=	-j
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java client library for the Spread Group Communication System

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	YES
JAVA_VERSION=	1.6+
PKGMESSAGE=	${WRKSRC}/../license.txt

ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	javadocs jar
PORTDOCS+=	java
.endif
ANT_PARAMS+=	-Dlib.dir=${STAGEDIR}${JAVAJARDIR} -Djavadoc.destdir=docs -Dversion=${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}/java
PLIST_SUB+=	PORTNAME="${PORTNAME}" PORTVERSION="${PORTVERSION}"

do-build:
	@cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT} ${ANT_TARGET} ${ANT_PARAMS}

do-install:
	@cd ${WRKSRC} && ${ANT} install ${ANT_PARAMS}
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${EXAMPLESDIR}/java
	${INSTALL_DATA} ${WRKSRC}/recThread.java ${STAGEDIR}${EXAMPLESDIR}/java
	${INSTALL_DATA} ${WRKSRC}/Flooder.java ${STAGEDIR}${EXAMPLESDIR}/java
	${INSTALL_DATA} ${WRKSRC}/User.java ${STAGEDIR}${EXAMPLESDIR}/java
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${DOCSDIR}/java
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/java
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${DOCSDIR}/java/html
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${DOCSDIR}/java/html/spread
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${DOCSDIR}/java/html/spread/class-use
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/docs/stylesheet.css ${STAGEDIR}${DOCSDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/docs/spread/*.html ${STAGEDIR}${DOCSDIR}/java/html/spread
	${INSTALL_DATA} ${WRKSRC}/docs/spread/class-use/*.html ${STAGEDIR}${DOCSDIR}/java/html/spread/class-use
.endif

.include <bsd.port.mk>
