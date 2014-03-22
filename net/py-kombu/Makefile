# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kombu
PORTVERSION=	3.0.10
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	AMQP messaging framework for Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amqp>=1.4.1:${PORTSDIR}/net/py-amqp \
		${PYTHON_PKGNAMEPREFIX}anyjson>=0.3.3:${PORTSDIR}/devel/py-anyjson

OPTIONS_DEFINE=	BEANSTALK BOTO MONGODB REDIS SQLALCHEMY ZMQ

BEANSTALK_DESC=	Include beanstalkd transport support
BOTO_DESC=	Include AWS transport support
MONGODB_DESC=	Include MongoDB transport support
REDIS_DESC=	Include Redis transport support
SQLALCHEMY_DESC=Include SQLAlchemy transport support
ZMQ_DESC=	Include ZMQ transport support

BEANSTALK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beanstalkc>0:${PORTSDIR}/net/py-beanstalkc
BOTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>=2.6.0:${PORTSDIR}/devel/py-boto
MONGODB_RUN_DEPENDS=	pymongo>0:${PORTSDIR}/databases/pymongo
REDI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>0:${PORTSDIR}/databases/py-redis
SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy
ZMQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.2.0:${PORTSDIR}/net/py-pyzmq

# Ports infrastructure bug
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
