# $FreeBSD$

PORTNAME=	ldap0
PORTVERSION=	0.0.60
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Python module package for implementing LDAP clients

LICENSE=	PSFL

MAKE_ENV+=	INCLUDES=${LOCALBASE}/include
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.2.1:devel/py-pyasn1-modules@${PY_FLAVOR}

USES=		python
USE_OPENLDAP=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
