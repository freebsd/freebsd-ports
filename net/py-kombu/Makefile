PORTNAME=	kombu
PORTVERSION=	5.6.2
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	AMQP messaging framework for Python
WWW=		https://kombu.readthedocs.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqp>=5.3.1,<6.0.0:net/py-amqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2026.2:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vine>=5.1.0,<6.0:devel/py-vine@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	MONGODB REDIS SQLALCHEMY SQS

MONGODB_DESC=		Include MongoDB transport support
REDIS_DESC=		Include Redis transport support
SQLALCHEMY_DESC=	Include SQLAlchemy transport support
SQS_DESC=		Include Amazon SQS transport support

MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=4.17.0:databases/py-pymongo@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>5.3.1,<8.0.0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4.48:databases/py-sqlalchemy14@${PY_FLAVOR}
SQS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.26.143:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>=7.43.0.5:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.16:net/py-urllib3@${PY_FLAVOR}

.include <bsd.port.mk>
