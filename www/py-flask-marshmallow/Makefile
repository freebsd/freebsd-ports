PORTNAME=	flask-marshmallow
PORTVERSION=	1.5.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flask_marshmallow-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Marshmallow support for Flask
WWW=		https://flask-marshmallow.readthedocs.io/en/latest/ \
		https://github.com/marshmallow-code/flask-marshmallow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>=4.0.0:devel/py-marshmallow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SQLALCHEMY
SQLALCHEMY_DESC=SQLAlchemy support

SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=3.0.0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}marshmallow-sqlalchemy>=1.4.0:databases/py-marshmallow-sqlalchemy@${PY_FLAVOR}

.include <bsd.port.mk>
