# New ports collection makefile for:    jdictionary
# Date created:         23.04.2002
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	jdictionary
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=jdictionary
DISTNAME=	jdictionary-1_8

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	JDictionary - Platform independent, plugin based dictionary

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jdk13

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/jdictionary
NO_BUILD=yes

do-configure:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${FILESDIR}/jdictionary.sh > ${WRKDIR}/jdictionary.sh

do-install:
	@if [ ! -d ${PREFIX}/share/java/classes/jdictionary ]; then \
		${MKDIR} ${PREFIX}/share/java/classes/jdictionary; fi
	${CP} ${WRKSRC}/jdictionary.jar                                \
		${PREFIX}/share/java/classes/jdictionary/
	${INSTALL_SCRIPT} ${WRKDIR}/jdictionary.sh ${PREFIX}/bin/jdictionary

.include <bsd.port.mk>
