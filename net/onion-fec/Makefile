# New ports collection makefile for:	Java OnionNetworks FEC
# Date created:				Wed Apr  5 03:10:31 UTC 2006
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fec
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	http://onionnetworks.com/downloads/
PKGNAMEPREFIX=	onion-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Forward Error Correction (FEC) library from OnionNetworks

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	\
		${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j

USE_ZIP=	yes
USE_ANT=	yes
JAVA_BUILD=	jdk
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
ALL_TARGET=	jars

.ifndef(NOPORTDOCS)
ALL_TARGET+=	javadoc

PORTDOCS+=	javadoc
.endif

# override DEFAULT
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

JAVADOC_WRKSRC=	${WRKSRC}/javadoc

# jars
JAR_FILES+=	\
		onion-common.jar \
		onion-fec.jar
PLIST_FILES+=	${JAR_FILES:S,^,%%JAVAJARDIR%%/,}

pre-build:
	@${LN} -sf ${JAVALIBDIR}/log4j.jar ${WRKSRC}/lib

do-install:
.ifndef(NOPORTDOCS)
# line taken from textproc/xerces-j maintained by hq@FreeBSD.org
	@cd ${JAVADOC_WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} "${DOCSDIR}/javadoc/{}" \; && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/javadoc/{}" \;
.endif
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/${jar} ${JAVAJARDIR}
.endfor

.include <bsd.port.mk>
