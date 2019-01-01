# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	h5py
PORTVERSION=	2.9.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	General-purpose Python interface to the HDF5 library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licenses/license.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${RUN_DEPENDS}
LIB_DEPENDS=	libhdf5.so:science/hdf5
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/h5py/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
