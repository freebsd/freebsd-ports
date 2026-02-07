PORTNAME=	debian-inspector
DISTVERSION=	31.1.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	debian_inspector-${DISTVERSION}

MAINTAINER=	tuukka.pasanen@ilmi.fi
COMMENT=	Utilities to parse Debian package, copyright and control files
WWW=		https://github.com/aboutcode-org/debian-inspector

LICENSE=	APACHE20 BSD3CLAUSE MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>25:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>5.2:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}commoncode>=32.2.1:devel/py-commoncode@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
