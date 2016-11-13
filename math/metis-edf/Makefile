# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	metis-edf
DISTVERSION=	4.0.3-1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Meshes partitioning tool used by Code_Aster

CONFLICTS=	metis-[0-9]* metis4-4*

ALL_TARGET=	default
MAKE_ENV=	PICFLAG="${PICFLAG}" prefix="${PREFIX}" OPTFLAGS="${CFLAGS}"

PICFLAG?=	-fPIC
LDFLAGS+=	-Wl,-soname,libmetis.so.0

WRKSRC=		${WRKDIR}/${PORTNAME:C|-edf||}-${PORTVERSION:R}

DOCS=		CHANGES Doc/manual.ps

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../french/aster/bsd.aster.mk"

MACHINEARCH=	${ARCH}
USE_LDCONFIG=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for df in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${df} ${STAGEDIR}${DOCSDIR}
. endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Graphs/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/Graphs/mtest ${STAGEDIR}${EXAMPLESDIR}

regression-test:
	(cd ${WRKSRC}/Graphs && LD_LIBRARY_PATH=${WRKSRC} ./mtest 4elt.graph || ${TRUE})

.include <bsd.port.post.mk>
