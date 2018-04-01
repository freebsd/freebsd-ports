# $FreeBSD$

PORTNAME=	pynleq2
DISTVERSION=	0.0.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP \
		https://github.com/PySCeS/pysces/archive/:fortran
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PYSCES_VERSION}${EXTRACT_SUFX}:fortran

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for NLEQ2 algorithm's fortran implementation

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}

USES=		fortran:flang python
USE_PYTHON=	distutils autoplist

BINARY_ALIAS=	gfortran6=flang # it keeps using gfortran6 regardless of the environment variables and arguments

PYSCES_VERSION=	0.9.5
FORTRAN_FILES=	linalg_nleq2.f nleq2.f wnorm.f zibconst.f zibmon.f zibsec.f

pre-build: # compile fortran files into a static library because distutils fails while doing this
	@${MKDIR} ${WRKDIR}/.fbuild && \
		cd ${WRKDIR}/.fbuild && \
		flang -c ${CFLAGS} -fPIC ${FORTRAN_FILES:C/^/${WRKDIR}\/pysces-${PYSCES_VERSION}\/pysces\/nleq2\//} && \
		${AR} -qc libff.a ${FORTRAN_FILES:S/.f/.o/}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nleq2.so

.include <bsd.port.mk>
