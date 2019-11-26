# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	jdictionary
DISTVERSION=	1_8
PORTREVISION=	4
CATEGORIES=	textproc java
MASTER_SITES=	SF/jdictionary/jDictionary/jDictionary%20version%20${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Platform independent, plugin based dictionary

USE_JAVA=	yes

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jdictionary.sh

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jdictionary.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/jdictionary.sh ${STAGEDIR}${PREFIX}/bin/jdictionary

.include <bsd.port.mk>
