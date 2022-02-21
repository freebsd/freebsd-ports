PORTNAME=	yq
DISTVERSION=	2.14.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line YAML and XML processor, jq wrapper for YAML/XML documents

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	jq:textproc/jq \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=1.8.1:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=5.3.1:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.11.0:devel/py-xmltodict@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

CONFLICTS_INSTALL=	go-yq

NO_ARCH=	yes

do-test: # tests fail: https://github.com/kislyuk/yq/issues/62
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
