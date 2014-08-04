# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedWords
PORTVERSION=	14.0.0
CATEGORIES=	net-im devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Words/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedWords-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twisted Words has more chat than you can handle

LICENSE=	MIT

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes
USES=		tar:bzip2 twisted

.include <bsd.port.mk>
