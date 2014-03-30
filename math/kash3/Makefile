# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	kash3
PORTVERSION=	2008.07.31
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.tu-berlin.de/pub/algebra/Kant/Kash_3/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTFILES=	${PORTNAME:U}-${ELFTYPE}-i686-${PORTVERSION:S|.|-|g}.tar.bz2

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A computer algebra system for computing in algebraic number fields

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

NO_CDROM=	Not for commercial distribution or use
NO_BUILD=	yes

OPTIONS_DEFINE=		OPTLIB DOCS
OPTIONS_DEFAULT=	OPTLIB
OPTLIB_DESC=		Install optional functions library

PLIST_SUB=	OPTLIB=${OPTLIB}

USE_BZIP2=	yes
USE_LINUX=	yes

SUB_FILES=	${PORTNAME}
WRKSRC=	${WRKDIR}/${PORTNAME:U}-${ELFTYPE}-i686-${PORTVERSION:S|.|-|g}


FIND_DATA=	-type f -mindepth 1 -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
FIND_DIRS=	-type d	-exec ${MKDIR} ${DATADIR}/{} \;
FIND_HERE=	data gap lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
FIND_HERE+=	html pdf
.endif

LN_OPTS=	-sf
ELFTYPE=	Linux

.if ${PORT_OPTIONS:MOPTLIB}
DISTFILES+=	${PORTNAME:U}-lib-archindep-${PORTVERSION:S|.|-|g}.tar.bz2
OPTLIB=
.else
OPTLIB=	"@comment "
.endif

do-install:
	${MKDIR} ${DATADIR};
.if ${PORT_OPTIONS:MOPTLIB}
	cd ${WRKDIR}/${PORTNAME:U}-lib-archindep-${PORTVERSION:S|.|-|g}; \
	${COPYTREE_SHARE} . ${DATADIR}
.endif
	cd ${WRKSRC}; \
	${FIND} ${FIND_HERE} ${FIND_DIRS}; \
	${FIND} ${FIND_HERE} ${FIND_DATA}; \
	${BRANDELF} -t ${ELFTYPE} ${PORTNAME}; \
	${INSTALL_PROGRAM} ${PORTNAME} ${DATADIR}/${PORTNAME};
	${INSTALL_SCRIPT} ${WRKDIR}/${SUB_FILES} ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}; \
	${MV} ${DATADIR}/html ${DATADIR}/pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
