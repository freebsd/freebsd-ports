PORTNAME=	meshio
PORTVERSION=	5.3.4
PORTREVISION=	1
CATEGORIES=	science cad python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	I/O for many mesh formats
WWW=		https://github.com/nschloe/meshio

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}netCDF4>0:science/py-netCDF4@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	distutils

NO_ARCH=	yes

PLIST_SUB=	PARAVIEW_VER=${PARAVIEW_VER}

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/share/paraview-5.9	\
		${STAGEDIR}${PREFIX}/lib/paraview-${PARAVIEW_VER}

.include <../../science/paraview/Makefile.version>
.include <bsd.port.mk>
