PORTNAME=	pygccxml
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package for easy C++ declarations navigation
WWW=		https://github.com/CastXML/pygccxml

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	castxml:textproc/castxml
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coveralls>0:devel/py-coveralls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail due to missing dependencies, see https://github.com/CastXML/pygccxml/issues/160

USE_GITHUB=	yes
GH_ACCOUNT=	CastXML

NO_ARCH=	yes

.include <bsd.port.mk>
