PORTNAME=	yq
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line YAML and XML processor, jq wrapper for YAML/XML documents

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	jq:textproc/jq \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=1.8.1:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=3.11:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.11.0:devel/py-xmltodict@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	kislyuk
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

do-test: # tests fail: https://github.com/kislyuk/yq/issues/62
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
