PORTNAME=	flask-migrate
PORTVERSION=	4.0.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-Migrate-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database schema migrations for Flask applications
WWW=		https://github.com/miguelgrinberg/Flask-Migrate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=1.9.0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.9:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=1.0:databases/py-flask-sqlalchemy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
