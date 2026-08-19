PORTNAME=	matrix-synapse-ldap3
PORTVERSION=	0.4.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	matrix_synapse_ldap3-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LDAP3 auth provider for Matrix Synapse
WWW=		https://github.com/matrix-org/matrix-synapse-ldap3

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=39.2.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap3>=2.8:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=14.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=15.1.0:devel/py-twisted@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
