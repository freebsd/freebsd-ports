# New ports collection makefile for:   dtdinst
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdinst
PORTVERSION=	2001.12.03
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/dtdinst/
DISTNAME=	${PORTNAME}
DISTFILES=	${JAR} dtdinst2rng.xsl index.html copying.txt
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes

JAR=		${DISTNAME}.jar
JAVALIBDIR=	${PREFIX}/share/java/classes
XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${JAR} ${JAVALIBDIR}
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.xsl ${XMLDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.txt ${DOCSDIR}

.include <bsd.port.mk>
