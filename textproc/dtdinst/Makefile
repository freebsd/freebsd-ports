# New ports collection makefile for:   dtdinst
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdinst
PORTVERSION=	2003.01.22
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/relaxng/dtdinst/
DISTNAME=	${PORTNAME}
DISTFILES=	dtdinst.jar dtdinst2rng.xsl index.html copying.txt
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org

USE_JAVA=	1.1+
NO_BUILD=	yes

NO_BUILD_DEPENDS_JAVA=	yes

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.jar ${JAVAJARDIR}
	${MKDIR} ${PREFIX}/share/xsl/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.xsl \
		${PREFIX}/share/xsl/${PORTNAME}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.txt ${DOCSDIR}

.include <bsd.port.mk>
