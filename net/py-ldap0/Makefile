# $FreeBSD$

PORTNAME=	ldap0
PORTVERSION=	0.0.60
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Python module package for implementing LDAP clients

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.2.1:devel/py-pyasn1-modules@${PY_FLAVOR}

MAKE_ENV+=	INCLUDES=${LOCALBASE}/include
WANT_OPENLDAP_SASL=yes

USES=		python:2.7
USE_OPENLDAP=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
