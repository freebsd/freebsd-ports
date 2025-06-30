PORTNAME=	pyreadstat
PORTVERSION=	1.3.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read and Write SAS, SPSS and Stata files into/from pandas data frames
WWW=		https://ofajardo.github.io/pyreadstat_documentation/_build/html/ \
		https://github.com/Roche/pyreadstat

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=1.2.0,1:math/py-pandas@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython3 pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
