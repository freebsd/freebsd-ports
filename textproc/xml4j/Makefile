# New ports collection makefile for:	XML for Java
# Date created:		21 Feb 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xml4j
PORTVERSION=	3.1.1
CATEGORIES=	textproc
MASTER_SITES=	http://apps.alphaworks.ibm.com/technologies/xml4j/
DISTNAME=	XML4J-J-bin.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	XML for Java parser

WRKSRC=		${WRKDIR}/XML4J-3_1_1
NO_BUILD=	YES

JAVASUBDIR=	jdk1.1.8
DIR=		${PREFIX}/share/java

do-install:
	@${MKDIR} ${DIR}/classes
	@(cd ${WRKSRC} && ${INSTALL_DATA} xml4j.jar xerces.jar xercesSamples.jar ${DIR}/classes)
	@${MKDIR} ${DIR}/xml4j
	@(cd ${WRKSRC} && ${INSTALL_DATA} Readme.html ${DIR}/xml4j)
	@(cd ${WRKSRC} && ${CP} -R data docs ${DIR}/xml4j)

.include <bsd.port.mk>
