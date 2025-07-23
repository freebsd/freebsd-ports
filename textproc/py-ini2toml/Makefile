PORTNAME=	ini2toml
PORTVERSION=	0.15
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically conversion of .ini/.cfg files to TOML equivalents
WWW=		https://ini2toml.readthedocs.io/en/latest/ \
		https://github.com/abravalheri/ini2toml

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=46.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=5:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20.7:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=59.6:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	FULL LITE
OPTIONS_DEFAULT=FULL
FULL_DESC=	Create TOML document with TOML-equivalent comment
LITE_DESC=	Create TOML document without comment

FULL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configupdater>=3.0.1<4:devel/py-configupdater@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tomlkit>=0.10.0<2:textproc/py-tomlkit@${PY_FLAVOR}
LITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli-w>=0.4.0<2:textproc/py-tomli-w@${PY_FLAVOR}

.include <bsd.port.mk>
