# New ports collection makefile for:	Azureus
# Date created:				October 6, 2004
# Whom:					Jeremy Faulkner <gldisater@gldis.ca>
#
# $FreeBSD$
#

PORTNAME=	azureus
PORTVERSION=	2.1.0.4
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Azureus${PORTVERSION}.jar
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	gldisater@gldis.ca
COMMENT=	A BitTorrent client written in Java

RUN_DEPENDS=	${LOCALBASE}/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
JAVA_RUN=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
JARFILE=	Azureus2.jar

PLIST_FILES=	%%DATADIR%%/${JARFILE} bin/${PORTNAME}

do-configure:
	${SED} -e "s+%%PREFIX%%+${PREFIX}+" -e "s+%%LOCALBASE%%+${LOCALBASE}+" \
		-e "s+%%JAVA%%+${JAVA}+" -e "s+%%DATADIR%%+${DATADIR}+" \
		${FILESDIR}/${PORTNAME} > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${DATADIR}/${JARFILE}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
