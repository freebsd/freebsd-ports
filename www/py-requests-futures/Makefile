# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requests-futures
PORTVERSION=	0.9.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS=	${PY_FUTURES} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
