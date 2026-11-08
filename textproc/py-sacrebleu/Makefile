PORTNAME=	sacrebleu
DISTVERSION=	2.6.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compute shareable BLEU, chrF, and TER scores for machine translation
WWW=		https://github.com/mjpost/sacrebleu

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portalocker>0:devel/py-portalocker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.8.9:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-patch:
	@${REINPLACE_CMD} -e 's/^license = "Apache-2.0"$$/license = {text = "Apache-2.0"}/' \
		-e 's/"setuptools>=77"/"setuptools>=63.1.0"/' \
		${WRKSRC}/pyproject.toml

NO_ARCH=	yes

.include <bsd.port.mk>
