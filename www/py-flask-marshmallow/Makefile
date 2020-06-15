# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flask-marshmallow
PORTVERSION=	0.13.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Marshmallow support for Flask

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>=2.0.0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SQLALCHEMY
SQLALCHEMY_DESC=SQLAlchemy support

SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}marshmallow-sqlalchemy>=0.13.0:databases/py-marshmallow-sqlalchemy@${PY_FLAVOR}

.include <bsd.port.mk>
