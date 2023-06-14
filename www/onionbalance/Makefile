PORTNAME=	onionbalance
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OnionBalance-${PORTVERSION}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Load-balancing and Redundancy for Onion Services
WWW=		https://onionbalance.readthedocs.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=0:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=0:security/py-stem@${PY_FLAVOR} \
		tor:security/tor

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
