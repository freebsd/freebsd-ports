# New ports collection makefile for:	geogebra-i18n
# Date created:		2005-08-26
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	geogebra-i18n
PORTVERSION=	2.6b
PORTREVISION=	3
CATEGORIES=	math java
MASTER_SITES=	http://www.geogebra.at/download/InstData/Java/ \
		http://nivi.interfree.it/distfiles/${DIST_SUBDIR}/
DISTNAME=	geogebra_setup
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A dynamic software that joins geometry, algebra and calculus

USE_JAVA=	yes
USE_ZIP=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
JAVA_VERSION=	1.4+
SUB_FILES=	${PORTNAME:S/-i18n$//}

FIND_DOCS=	-type f \! \( -name *.txt -or -name *.jar \)
FIND_ICONS=	-type f -name "*.gif" -maxdepth 1

SOURCES_DIR=	${WRKSRC}/D_/deploy/source
JARFILE=	${PORTNAME:S/-i18n$//}.jar

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SUB_FILES} ${PREFIX}/bin/${SUB_FILES}
	cd ${SOURCES_DIR} && ${MKDIR} ${DATADIR} && ${INSTALL_DATA} ${JARFILE} ${DATADIR};
.ifndef	NOPORTDOCS
	${MKDIR} ${DOCSDIR};
	cd ${SOURCES_DIR} && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${SOURCES_DIR} && ${FIND} . ${FIND_DOCS} -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif
	cd ${SOURCES_DIR}/.. && ${FIND} . ${FIND_ICONS} -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.include <bsd.port.mk>
