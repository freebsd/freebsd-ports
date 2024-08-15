PORTNAME=	eemeter
DISTVERSION=	4.0.5
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package implementing methods to calculate metered energy consumption
WWW=		https://eemeter.openee.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nlopt>0:math/py-nlopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=2.0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>0:math/py-statsmodels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # several tests fail, see https://github.com/openeemeter/eemeter/issues/508

.include <bsd.port.mk>
