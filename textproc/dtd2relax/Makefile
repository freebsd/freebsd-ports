# New ports collection makefile for:   dtd2relax
# Date created:                2 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtd2relax
PORTVERSION=	1.1.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.horobi.com/Projects/RELAX/Archive/
DISTNAME=	${PORTNAME:U}_${PORTVERSION:S/./_/g}
DISTFILES=	${JARFILE} ${DISTNAME}-src${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	fuyuki@mj.0038.net

USE_ZIP=	yes
USE_JAVA=	1.1+
NO_BUILD_DEPENDS_JAVA=	yes
NO_BUILD=	yes

JARFILE=	${DISTNAME}-bin-XML4J.jar
JAVALIBDIR=	${PREFIX}/share/java/classes

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${JAVALIBDIR}/${PORTNAME}.jar

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}

.include <bsd.port.mk>
