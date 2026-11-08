PORTNAME=	pynleq2
DISTVERSION=	0.1.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for NLEQ2 algorithm's fortran implementation
WWW=		https://github.com/bjodah/pynleq2

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		meson:devel/meson@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		fortran python
USE_PYTHON=	distutils autoplist pytest
USE_GITHUB=	nodefault
GH_TUPLE=	PySCeS:pysces:0.9.8:fortran

FORTRAN_FILES=	linalg_nleq2.f nleq2.f wnorm.f zibconst.f zibmon.f zibsec.f

pre-build: # copy fortran sources and build the extension with f2py
	@${CP} ${FORTRAN_FILES:C,^,${WRKSRC_fortran}/pysces/nleq2/,} ${WRKSRC}/nleq2/
	@cd ${WRKSRC}/nleq2 && \
		${SETENV} FC=${FC} F77=${F77} F90=${F90} FFLAGS="${FFLAGS}" \
			LDFLAGS="${LDFLAGS}" ${PYTHON_CMD} -m numpy.f2py -c -m nleq2 \
			nleq2.pyf ${FORTRAN_FILES} -lexecinfo
	@${MV} ${WRKSRC}/nleq2/nleq2*.so ${WRKSRC}/pynleq2/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nleq2*.so

# tests as of 0.1.0: 1 passed

.include <bsd.port.mk>
