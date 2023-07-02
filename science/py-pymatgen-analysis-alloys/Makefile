PORTNAME=	pymatgen-analysis-alloys
DISTVERSION=	0.0.6
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyMatgen add-on library with classes useful for describing alloys
WWW=		https://github.com/materialsproject/pymatgen-analysis-alloys

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymatgen>=2022.0.16:science/py-pymatgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>0:devel/py-shapely@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
