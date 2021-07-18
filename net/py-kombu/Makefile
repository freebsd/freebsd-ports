# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>

PORTNAME=	kombu
PORTVERSION=	4.6.11
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	AMQP messaging framework for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqp>=2.6.0<2.7:net/py-amqp@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BOTO MONGODB REDIS SQLALCHEMY ZMQ

BOTO_DESC=	Include AWS transport support
MONGODB_DESC=	Include MongoDB transport support
REDIS_DESC=	Include Redis transport support
SQLALCHEMY_DESC=Include SQLAlchemy transport support
ZMQ_DESC=	Include ZMQ transport support

BOTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>=2.6.0:devel/py-boto@${PY_FLAVOR}
MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=3.3.0:databases/pymongo@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR}
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR}
ZMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=13.1.0:net/py-pyzmq@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0.18:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
