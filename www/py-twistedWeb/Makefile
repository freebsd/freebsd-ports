# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedWeb
PORTVERSION=	15.2.1
CATEGORIES=	www devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Web/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWeb-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	HTTP protocol implementation together with clients and servers

LICENSE=	MIT

DEPRECATED=	Use devel/py-twisted instead
EXPIRATION_DATE=2017-09-30

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:2 tar:bzip2 twisted

.include <bsd.port.mk>
