# New ports collection makefile for:	jabref
# Date created:				18 Jan 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$

PORTNAME=	jabref
PORTVERSION=	2.0b2
CATEGORIES=	print java editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	JabRef-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	#

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A (BibTeX native) bibliographic reference manager

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JARNAME=${DISTFILES}

PLIST_FILES=	%%DATADIR%%/${DISTFILES} \
		bin/${PORTNAME}
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
