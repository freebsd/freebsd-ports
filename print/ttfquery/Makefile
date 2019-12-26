# Created by: ijliao
# $FreeBSD$

PORTNAME=	ttfquery
PORTVERSION=	1.0.5
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	CHEESESHOP
DISTNAME=	TTFQuery-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FontTools-based package for querying system fonts

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>0:print/py-fonttools@${PY_FLAVOR} \
		${PYNUMPY}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
