# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTNAME=	h5py
PORTVERSION=	2.2.0
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	General-purpose Python interface to the HDF5 library

LICENSE=	BSD

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5-18

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
