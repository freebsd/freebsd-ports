PORTNAME=	octave-forge-mpi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BROKEN=		does not build with octave>=8

LIB_DEPENDS+=	libmpi.so:net/mpich

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	carlodefalco
GH_PROJECT=	octave-mpi

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

post-patch:
	${REINPLACE_CMD} 's/= NULL/= 0/g' ${WRKSRC}/*.cc ${WRKSRC}/*.h

.include <bsd.port.mk>
