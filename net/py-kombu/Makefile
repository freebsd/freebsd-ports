# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kombu
PORTVERSION=	3.0.32
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	AMQP messaging framework for Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqp>=1.4.7:net/py-amqp \
		${PYTHON_PKGNAMEPREFIX}anyjson>=0.3.3:devel/py-anyjson

OPTIONS_DEFINE=	BEANSTALK BOTO MONGODB REDIS SQLALCHEMY ZMQ

BEANSTALK_DESC=	Include beanstalkd transport support
BOTO_DESC=	Include AWS transport support
MONGODB_DESC=	Include MongoDB transport support
REDIS_DESC=	Include Redis transport support
SQLALCHEMY_DESC=Include SQLAlchemy transport support
ZMQ_DESC=	Include ZMQ transport support

BEANSTALK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beanstalkc>0:net/py-beanstalkc
BOTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>=2.6.0:devel/py-boto
MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>0:databases/pymongo
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy07>0:databases/py-sqlalchemy07
ZMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=13.1.0:net/py-pyzmq


USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
