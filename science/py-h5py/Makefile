# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	h5py
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	General-purpose Python interface to the HDF5 library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licenses/license.txt

BUILD_DEPENDS=	${PYNUMPY} \
		cython:${PORTSDIR}/lang/cython
RUN_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5

USE_GITHUB=	yes

USES=		python
USE_PYTHON=	autoplist distutils

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
