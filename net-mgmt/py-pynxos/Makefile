PORTNAME=	pynxos
DISTVERSION=	0.0.5
PORTREVISION=	3
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Python client for managing Cisco NX-OS devices through NX-API
WWW=		https://github.com/networktocode/pynxos

LICENSE=	APACHE20

DEPRECATED=	Upstream inactive since +7 years, was used by py-napalm for a while, until it was replaced by py-nxapi-plumbing. Please use net-mgmt/py-napalm instead
EXPIRATION_DATE=2026-07-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scp>0:security/py-scp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
