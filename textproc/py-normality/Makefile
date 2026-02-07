PORTNAME=	normality
DISTVERSION=	2.5.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Micro-library to normalize text strings
WWW=		https://github.com/pudo/normality

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}banal>=1.0.1:devel/py-banal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2.0.0:textproc/py-charset-normalizer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=		ICU
OPTIONS_DEFAULT=	ICU

ICU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=1.9.3:devel/py-pyicu@${PY_FLAVOR}

.include <bsd.port.mk>
