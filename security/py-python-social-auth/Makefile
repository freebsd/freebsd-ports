# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-social-auth
PORTVERSION=	0.2.21
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Python Social Auth is a social authentication/registration mechanism

LICENSE=	BSD3CLAUSE

RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}python-openid>=2.2:security/py-python-openid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0.3.8:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.3.1:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.2.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.0.0:www/py-pyjwt@${PY_FLAVOR}

DEPRECATED=	Upstream Deprecated
EXPIRATION_DATE=	2018-08-01

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
