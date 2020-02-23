# $FreeBSD$

PORTNAME=	bitmath
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}-4.tar.gz

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Represent and manipulate file sizes with different prefix notations

LICENSE=	MIT

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7
USE_PYTHON=	autoplist distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-4

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}progressbar231>0:misc/py-progressbar231@${PY_FLAVOR}

.include <bsd.port.mk>
