PORTNAME=	checkdmarc
PORTVERSION=	5.9.2
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module and command line parser for SPF and DMARC records
WWW=		https://domainaware.github.io/checkdmarc/ \
		https://github.com/domainaware/checkdmarc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=2.0.0,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}expiringdict>=1.1.4:devel/py-expiringdict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=6.0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pem>=23.1.0:security/py-pem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}publicsuffixlist>=0.10.0:dns/py-publicsuffixlist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyleri>=1.3.2:devel/py-pyleri@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=24.2.1,1:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timeout-decorator>=0.4.1:devel/py-timeout-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.14.2:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
