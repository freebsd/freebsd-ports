PORTNAME=	dftd4
DISTVERSION=	3.7.0
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python API of the DFT-D4 project
WWW=		https://www.chemie.uni-bonn.de/pctc/mulliken-center/software/dftd4/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libdftd4.so:science/dftd4
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYNUMPY}

USES=		pkgconfig python
USE_PYTHON=	pep517 autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/dftd4/_libdftd4${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
