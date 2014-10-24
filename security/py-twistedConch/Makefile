# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedConch
PORTVERSION=	14.0.0
CATEGORIES=	security devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Conch/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedConch-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	SSH and SFTP protocol implementation with clients and servers

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.0.9a:${PORTSDIR}/devel/py-asn1

USE_PYTHON=	distutils autoplist
USES=		python:2 tar:bzip2 twisted

.include <bsd.port.mk>
