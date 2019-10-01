# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	3.44.0
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-ufo

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dependencies for ufo functionality of FontTools

RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}fs2>=2.2.0<3:devel/py-fs2@${PY_FLAVOR}

USES=		metaport python:env
USE_PYTHON=	flavors

.include <bsd.port.mk>
