# New ports collection makefile for:   dtdinst
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdinst
PORTVERSION=	2002.07.24
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/dtdinst/
DISTNAME=	${PORTNAME}
DISTFILES=	${JARFILE} dtdinst2rng.xsl index.html copying.txt
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	fuyuki@hadaly.org

USE_JAVA=	1.1+
NO_BUILD_DEPENDS_JAVA=	yes
NO_BUILD=	yes

JARFILE=	${DISTNAME}.jar
JAVALIBDIR=	${PREFIX}/share/java/classes
XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${JARFILE} ${JAVALIBDIR}
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.xsl ${XMLDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.txt ${DOCSDIR}

.include <bsd.port.mk>
