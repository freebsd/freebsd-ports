# New ports collection makefile for:	jabref
# Date created:				18 Jan 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$

PORTNAME=	jabref
PORTVERSION=	2.6
CATEGORIES=	print java editors
MASTER_SITES=	SF
DISTNAME=	JabRef-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	#

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A (BibTeX native) bibliographic reference manager

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${PORTNAME}.jar

PLIST_FILES=	%%DATADIR%%/${PORTNAME}.jar \
		bin/${PORTNAME}
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${DATADIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
