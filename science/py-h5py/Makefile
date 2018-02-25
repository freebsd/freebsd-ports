# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	h5py
DISTVERSION=	2.7.1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General-purpose Python interface to the HDF5 library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licenses/license.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>0:devel/py-pkgconfig@${FLAVOR}
LIB_DEPENDS=	libhdf5.so:science/hdf5
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils cython autoplist concurrent

PORTDOCS=	*
PORTEXAMPLES=	multiprocessing_example.py swmr_multiprocess.py \
		swmr_inotify_example.py  threading_example.py

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/docs ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/h5py/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
