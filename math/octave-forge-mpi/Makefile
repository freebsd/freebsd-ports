PORTNAME=	octave-forge-mpi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	carlodefalco
GH_PROJECT=	octave-mpi

LIB_DEPENDS+=	libmpi.so:net/mpich

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${GH_PROJECT}-${DISTVERSION}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-patch:
	${REINPLACE_CMD} 's/= NULL/= 0/g' ${WRKSRC}/*.cc ${WRKSRC}/*.h

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
