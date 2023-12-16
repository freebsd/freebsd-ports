PORTNAME=	flask-marshmallow
PORTVERSION=	0.15.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Marshmallow support for Flask
WWW=		https://github.com/marshmallow-code/flask-marshmallow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>=2.0.0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SQLALCHEMY
SQLALCHEMY_DESC=SQLAlchemy support

SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=3.0.0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}marshmallow-sqlalchemy>=0.28.2:databases/py-marshmallow-sqlalchemy@${PY_FLAVOR}

.include <bsd.port.mk>
