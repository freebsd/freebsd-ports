# New ports collection makefile for:   dtdinst
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdinst
PORTVERSION=	2003.06.19
CATEGORIES=	textproc java
MASTER_SITES=	http://www.thaiopensource.com/download/
DISTNAME=	${PORTNAME}-20030619
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts DTDs to XML instance, in a specific or RELAX NG format

USE_ZIP=	YES
USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.jar ${JAVAJARDIR}
	${MKDIR} ${PREFIX}/share/xsl/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.xsl ${PREFIX}/share/xsl/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dtdinst.rng ${DOCSDIR}
.endif

.include <bsd.port.mk>
