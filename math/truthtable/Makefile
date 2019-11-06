# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	truthtable
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	math java
MASTER_SITES=	http://www.kinostudios.com/java/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/
DISTNAME=	TruthTable
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Truth Tables generator (written in Java)

BROKEN=		unfetchable

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}
SUB_LIST=	TRUTHTABLEJAR=${TRUTHTABLEJAR}

TRUTHTABLEJAR=	${DATADIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
