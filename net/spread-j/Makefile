# New ports collection makefile for:    spread-j
# Date created:		06 November 2002
# Whom:			Joshua Goodall <joshua@roughtrade.net>
#
# $FreeBSD$
#

PORTNAME=	spread-j
PORTVERSION=	3.17.1
CATEGORIES=	net java
MASTER_SITES=	http://www.cnds.jhu.edu/download/noformdown/
DISTNAME=	spread-src-${PORTVERSION}

MAINTAINER=	joshua@roughtrade.net
COMMENT=	Java client library for the Spread Group Communication System

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.2+
USE_JIKES=	yes
JAVALIBDIR=	${PREFIX}/share/java/classes
PKGMESSAGE=	${WRKSRC}/../license.txt

ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
PLIST_SUB+=	JAVALIB_DOCS='@comment '
ANT_TARGET=	jar
.else
PLIST_SUB+=	JAVALIB_DOCS=''
ANT_TARGET=	javadocs jar
PORTDOCS+=	html readme.txt
.endif
ANT_PARAMS+=	-Dlib.dir=${JAVALIBDIR} -Djavadoc.destdir=docs -Dversion=${PORTVERSION}

WRKSRC=		${WRKDIR}/${DISTNAME}/java
PLIST_SUB+=	JAVALIBDIR=share/java/classes

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET} ${ANT_PARAMS}

do-install:
	@cd ${WRKSRC} && ${ANT} install ${ANT_PARAMS}
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/recThread.java ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Flooder.java ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/User.java ${EXAMPLESDIR}
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/html
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/html/spread
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/html/spread/class-use
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/stylesheet.css ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/spread/*.html ${DOCSDIR}/html/spread
	${INSTALL_DATA} ${WRKSRC}/docs/spread/class-use/*.html ${DOCSDIR}/html/spread/class-use
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
