# Created by: Bruce Simpson
# $FreeBSD$

PORTNAME=	txamqp
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	http://launchpadlibrarian.net/30388120/ \
		# http://launchpad.net/txamqp/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twisted Python library for the AMQP messaging protocol

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}thrift>=0:devel/py-thrift \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	autoplist distutils

WRKSRC=		${WRKDIR}/python-${PORTNAME}-${PORTVERSION}

# TODO: Install txAMQP examples.

.include <bsd.port.mk>
