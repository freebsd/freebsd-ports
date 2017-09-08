# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedWords
PORTVERSION=	15.2.1
CATEGORIES=	net-im devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Words/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWords-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twisted Words has more chat than you can handle

LICENSE=	MIT

DEPRECATED=	Use devel/py-twisted instead
EXPIRATION_DATE=2017-09-30

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:2 tar:bzip2 twisted

.include <bsd.port.mk>
