# New ports collection makefile for:    spread-j
# Date created:		06 November 2002
# Whom:			Joshua Goodall <joshua@roughtrade.net>
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	3.17.2
CATEGORIES=	net java
MASTER_SITES=	http://www.cnds.jhu.edu/download/noformdown/
PKGNAMESUFFIX=	-j
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	joshua@roughtrade.net
COMMENT=	Java client library for the Spread Group Communication System

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	YES
JAVA_VERSION=	1.2+
PKGMESSAGE=	${WRKSRC}/../license.txt

ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	javadocs jar
PORTDOCS+=	java
.endif
ANT_PARAMS+=	-Dlib.dir=${JAVAJARDIR} -Djavadoc.destdir=docs -Dversion=${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}_src-${PORTVERSION}/java
PLIST_SUB+=	PORTNAME="${PORTNAME}" PORTVERSION="${PORTVERSION}"

do-build:
	@cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT} ${ANT_TARGET} ${ANT_PARAMS}

do-install:
	@cd ${WRKSRC} && ${ANT} install ${ANT_PARAMS}
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${EXAMPLESDIR}/java
	${INSTALL_DATA} ${WRKSRC}/recThread.java ${EXAMPLESDIR}/java
	${INSTALL_DATA} ${WRKSRC}/Flooder.java ${EXAMPLESDIR}/java
	${INSTALL_DATA} ${WRKSRC}/User.java ${EXAMPLESDIR}/java
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/java
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/java
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/java/html
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/java/html/spread
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/java/html/spread/class-use
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/docs/stylesheet.css ${DOCSDIR}/java/html
	${INSTALL_DATA} ${WRKSRC}/docs/spread/*.html ${DOCSDIR}/java/html/spread
	${INSTALL_DATA} ${WRKSRC}/docs/spread/class-use/*.html ${DOCSDIR}/java/html/spread/class-use
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
