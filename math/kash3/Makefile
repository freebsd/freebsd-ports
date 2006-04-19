# New ports collection makefile for:	kash3
# Date created:		2006-02-26
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	kash3
PORTVERSION=	2006.01.31
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.tu-berlin.de/pub/algebra/Kant/Kash_3/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTNAME=	${PORTNAME:U}-${ELFTYPE}-${PORTVERSION:S|.|-|g}

MAINTAINER=	nivit@email.it
COMMENT=	A computer algebra system for computing in algebraic number fields

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

NO_CDROM=	not for commercial distribution or use
NO_BUILD=	yes

USE_BZIP2=	yes
USE_LINUX=	yes

SUB_FILES=	${PORTNAME}
WRKSRC=	${WRKDIR}/${DISTNAME}

FIND_DATA=	-type f -mindepth 1 -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
FIND_DIRS=	-type d	-exec ${MKDIR} ${DATADIR}/{} \;
FIND_HERE=	data gap lib

.if !defined(NOPORTDOCS)
FIND_HERE+=	html pdf
.endif

LN_OPTS=	-sf
ELFTYPE=	Linux

do-install:
	${MKDIR} ${DATADIR};
	cd ${WRKSRC}; \
	${FIND} ${FIND_HERE} ${FIND_DIRS}; \
	${FIND} ${FIND_HERE} ${FIND_DATA}; \
	${BRANDELF} -t ${ELFTYPE} ${PORTNAME}; \
	${INSTALL_PROGRAM} ${PORTNAME} ${DATADIR}/${PORTNAME};
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}; \
	${MV} ${DATADIR}/html ${DATADIR}/pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
