PORTNAME=	python3-openid
PORTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python 3 port of the python-openid library
WWW=		https://github.com/necaris/python3-openid

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	MYSQL POSTGRESQL
MYSQL_DESC=	MySQL support
POSTGRESQL_DESC=PostgreSQL support

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysql-connector-python>=0:databases/py-mysql-connector-python@${PY_FLAVOR}
POSTGRESQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}

.include <bsd.port.mk>
