PORTNAME=	mnnpy
DISTVERSION=	0.1.9.5
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MNN (Mutual Nearest Neighbors) correct in python
WWW=		https://github.com/chriscainx/mnnpy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anndata>0:devel/py-anndata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils cython autoplist

post-patch:
.if defined(CPUTYPE)
.  if ${ARCH:Mpowerpc*}
	@${REINPLACE_CMD} -e "s|'-march=native'|'-mcpu=${CPUTYPE}'|" ${WRKSRC}/setup.py
.  else
	@${REINPLACE_CMD} -e "s|'-march=native'|'-march=${CPUTYPE}'|" ${WRKSRC}/setup.py
.  endif
.else
	@${REINPLACE_CMD} -e "s|'-march=native', ||" ${WRKSRC}/setup.py
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/mnnpy/_utils.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
