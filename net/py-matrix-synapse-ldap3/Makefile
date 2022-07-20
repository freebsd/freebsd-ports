PORTNAME=	matrix-synapse-ldap3
PORTVERSION=	0.2.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LDAP3 auth provider for Matrix Synapse

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap3>=2.8:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=15.1.0:devel/py-twisted@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
