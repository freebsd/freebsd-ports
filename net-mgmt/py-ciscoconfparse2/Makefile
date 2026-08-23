PORTNAME=	ciscoconfparse2
DISTVERSION=	0.9.18
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parse, audit, query, build and modify Cisco IOS-style configurations
WWW=		https://github.com/mpenning/ciscoconfparse2

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=25.4.0<27.0.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.8.0,1<3,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hier-config>=2.3.1<2.3.1_99:net-mgmt/py-hier-config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.152.7<7:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}loguru>=0.7.2:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}macaddress>=2.0.2<2.0.2_99:net/py-macaddress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.7.4:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.3.2<4:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=14.3.3:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2<1:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.15.0<6:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typeguard>=4.5.2<5:devel/py-typeguard@${PY_FLAVOR}

USES=		python

USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
