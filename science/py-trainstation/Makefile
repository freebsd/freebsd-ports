PORTNAME=	trainstation
DISTVERSION=	1.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convenient training of linear models
WWW=		https://trainstation.materialsmodeling.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

xBUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 10 tests fail, see https://gitlab.com/materials-modeling/trainstation/-/issues/10

NO_ARCH=	yes

.include <bsd.port.mk>
