# New ports collection makefile for:   dtd2relax
# Date created:                2 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtd2relax
PORTVERSION=	1.1.1
CATEGORIES=	textproc java
MASTER_SITES=	http://www.horobi.com/Projects/RELAX/Archive/
DISTNAME=	${PORTNAME:U}_${PORTVERSION:S/./_/g}
DISTFILES=	${JARFILE} ${DISTNAME}-src${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DTD to RELAX converter for Java

USE_ZIP=	yes
USE_JAVA=	yes
NO_BUILD=	yes

JARFILE=	${DISTNAME}-bin-XML4J.jar
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${JAVAJARDIR}/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
