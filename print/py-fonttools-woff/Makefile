# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	3.44.0
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-woff

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dependencies for woff functionality of FontTools

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.0.1:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zopfli>=0.1.4:archivers/py-zopfli@${PY_FLAVOR}

USES=		metaport python:env
USE_PYTHON=	flavors

.include <bsd.port.mk>
