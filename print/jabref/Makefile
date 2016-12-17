# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	jabref
PORTVERSION=	3.8
PORTEPOCH=	1
CATEGORIES=	print java editors
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}/ \
		http://builds.jabref.org/ \
		https://github.com/JabRef/jabref/releases/download/v${PORTVERSION}/
DISTNAME=	JabRef-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	#

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	BibTeX native bibliographic reference manager

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

PORTSCOUT=	limit:.*[0-9]$$

USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
icon=		${DATADIR}/${PORTNAME}-icon48x48.png

SUB_FILES=	${PORTNAME}.sh ${PORTNAME}.desktop
SUB_LIST=	JARNAME=${PORTNAME}.jar

USES=		desktop-file-utils

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/JabRef-icon-48.png ${STAGEDIR}${icon}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
