PORTNAME=	cowrie
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.14
CATEGORIES=	security python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cowrie SSH/Telnet honeypot
WWW=		https://www.cowrie.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}attrs>=26.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=5.0.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=50.0.0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperlink>=21.0.0:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.18:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>=1.3.1:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=26.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.4.1:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=26.1.0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treq>=22.2.0:www/py-treq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=25.5.0:devel/py-twisted@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	pep517 autoplist noflavors

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION="${PORTVERSION}"

CONFLICTS_INSTALL=	py*-asciinema # bin/asciinema

NO_ARCH=	yes

post-patch: # in pyproject.toml patch first == into >= to avoid deps failures due to exact version requirements
	@${REINPLACE_CMD} \
		-e 's/setuptools>=80/setuptools>=63.1.0/' \
		-e 's/pyasn1_modules>=0.4.2/pyasn1_modules>=0.4.1/' \
		-e 's/treq>=26.7.0/treq>=22.2.0/' \
		-e 's/twisted\\[conch\\]>=26.4.0/twisted[conch]>=25.5.0/' \
		-e 's/==/>=/' \
		${WRKSRC}/pyproject.toml

do-test:
	@cd ${WRKSRC} && ${SETENV} PYTHONPATH=${WRKSRC}/src ${PYTHON_CMD} -m unittest discover src/cowrie/test -v

# tests as of 3.0.14: Ran 1101 tests in 28.389s, OK (skipped=2)

.include <bsd.port.mk>
