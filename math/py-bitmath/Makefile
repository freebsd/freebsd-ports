# $FreeBSD$

PORTNAME=	bitmath
PORTVERSION=	1.2.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}-4.tar.gz

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Represent and manipulate file sizes with different prefix notations

LICENSE=	MIT

USES=		python:2
USE_PYTHON=	autoplist distutils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-4

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}progressbar231>0:misc/py-progressbar231

.include <bsd.port.mk>
