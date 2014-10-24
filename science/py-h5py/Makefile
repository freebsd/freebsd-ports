# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	h5py
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	General-purpose Python interface to the HDF5 library

LICENSE=	BSD

BUILD_DEPENDS=	${PYNUMPY} \
		cython:${PORTSDIR}/lang/cython
RUN_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5

USE_GITHUB=		yes
GH_ACCOUNT=		h5py
GH_COMMIT=		c8c63eb
GH_TAGNAME=		${GH_COMMIT}

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	README.rst
PORTEXAMPLES=	multiprocessing_example.py \
		threading_example.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${STAGEDIR}${EXAMPLESDIR}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
