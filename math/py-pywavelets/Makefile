PORTNAME=	pywavelets
PORTVERSION=	1.5.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Discrete Wavelet Transforms in Python
WWW=		https://github.com/PyWavelets/pywt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0.14:devel/meson-python@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python shebangfix
USE_PYTHON=	autoplist cython pep517

SHEBANG_FILES=	pywt/data/create_dat.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pywt/_extensions/*.so

.include <bsd.port.mk>
