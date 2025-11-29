PORTNAME=	cowrie
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.0
CATEGORIES=	security python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cowrie SSH/Telnet honeypot
WWW=		https://www.cowrie.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.rst

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}attrs>=25.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=5.0.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=46.0.3:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperlink>=21.0.0:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.11:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>0:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=24.2.0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tftpy>=0.8.6:ftp/py-tftpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treq>0:www/py-treq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.5.0:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	pep517 cryptography autoplist noflavors

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION="${PORTVERSION}"

CONFLICTS_INSTALL=	py*-asciinema # bin/asciinema

NO_ARCH=	yes

.include <bsd.port.mk>
