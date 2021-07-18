# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	matrix-synapse-ldap3
PORTVERSION=	0.1.5
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LDAP3 auth provider for Matrix Synapse

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap3>=2.8:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=15.1.0:devel/py-twisted@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
