# New ports collection makefile for:    Xerces
# Date created:		2000/08/12
# Whom:			Marcin Cieslak
#
# $FreeBSD$
#

PORTNAME=	xerces-j
PORTVERSION=	2.0.2
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/xerces-j/
DISTNAME=	xerces-${PORTVERSION:S/./_/g}
DISTFILES=	Xerces-J-bin.${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	kevlo@FreeBSD.org

USE_JAVA=	1.3+

WRKSRC=		${WRKDIR}/xerces-${PORTVERSION:S/./_/g}
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} xercesImpl.jar xmlParserAPIs.jar \
		${PREFIX}/share/java/classes)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${TAR} -cf - . | ${TAR} -xf - -C ${DOCSDIR})
.endif

.include <bsd.port.mk>
