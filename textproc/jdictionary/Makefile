# New ports collection makefile for:    jdictionary
# Date created:         23.04.2002
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	jdictionary
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,_,}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Platform independent, plugin based dictionary

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.3+

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jdictionary.sh

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jdictionary.jar ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/jdictionary.sh ${PREFIX}/bin/jdictionary

.include <bsd.port.mk>
