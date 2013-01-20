# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	jabref
PORTVERSION=	2.9.2
PORTEPOCH=	1
CATEGORIES=	print java editors
MASTER_SITES=	SF
DISTNAME=	JabRef-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	#

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	BibTeX native bibliographic reference manager

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
icon=		${DATADIR}/${PORTNAME}-icon48x48.png

SUB_FILES=	${PORTNAME}.sh ${PORTNAME}.desktop
SUB_LIST=	JARNAME=${PORTNAME}.jar

USE_GNOME=	desktopfileutils

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${DATADIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/JabRef-icon-48.png "${icon}"
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${DESKTOPDIR}
	-${LOCALBASE}/bin/update-desktop-database -q

.include <bsd.port.mk>
