PORTNAME=	requests-kerberos
PORTVERSION=	0.15.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	requests_kerberos-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Kerberos authentication handler for python-requests
WWW=		https://github.com/requests/requests-kerberos

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyspnego>=0:security/py-pyspnego@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.1.0:www/py-requests@${PY_FLAVOR}
# pyspnego[kerberos]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.6.0:security/py-gssapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}krb5>=0.3.0:security/py-krb5@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
