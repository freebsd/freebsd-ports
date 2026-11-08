PORTNAME=	ciscoconfparse
DISTVERSION=	1.9.52
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parse, audit, query, build and modify Cisco IOS-style configurations
WWW=		https://www.pennington.net/py/ciscoconfparse/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream repo archived on 5th March 2025. Please use net-mgmt/py-ciscoconfparse2 instead
EXPIRATION_DATE=2026-11-30

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.6.1:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.38.4:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>=1.2.14:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.4.2,1<3,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hier-config>=2.2.3<3:net-mgmt/py-hier-config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}loguru>=0.7.2:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.7.4<2:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
# Test fails due missing files:
# - fixtures/configs/sample_01.{asa,f5,ios,iosxr,junos,nxosf}
PYTEST_BROKEN_TESTS=	testIPv6Obj_IPv4_embedded_in_IPv6_04 \
			testParse_parse_syntax_f5_as_junos_nofactory_ioscfg_01 \
			testParse_syntax \
			testVal_JunosCfgLine_child_02 \
			testVal_JunosCfgLine_child_03 \
			testVal_JunosCfgLine_child_04

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
