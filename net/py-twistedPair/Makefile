# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedPair
PORTVERSION=	13.2.0
CATEGORIES=	net devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Pair/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedPair-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twisted Pair can do low level TCP work

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>=${PORTVERSION}:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	${PORTNAME:S/twisted/Twisted_/}

NO_STAGE=	yes
.include <bsd.port.mk>
