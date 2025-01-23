PORTNAME=	pyphot
DISTVERSION=	1.6.0
CATEGORIES=	science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computing photometry from spectra
WWW=		https://mfouesneau.github.io/pyphot/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>4.0:astro/py-astropy@${PY_FLAVOR} \
		${PYNUMPPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0.9:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>3.0:devel/py-tables@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 1.6.0: 16 passed, 5 warnings in 27.42s

.include <bsd.port.mk>
