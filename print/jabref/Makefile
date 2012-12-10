# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	jabref
PORTVERSION=	2.8.1
PORTEPOCH=	1
CATEGORIES=	print java editors
MASTER_SITES=	SF
DISTNAME=	JabRef-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BibTeX native bibliographic reference manager

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_JAVA=	yes
JAVA_VERSION=	1.6+
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
