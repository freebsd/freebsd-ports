PORTNAME=	flask-migrate
PORTVERSION=	3.0.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-Migrate-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database schema migrations for Flask applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.9:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=1.0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic>=0.7:databases/py-alembic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
