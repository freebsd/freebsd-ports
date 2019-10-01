# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	3.44.0
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-lxml

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dependencies for lxml functionality of FontTools

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.0<5:devel/py-lxml@${PY_FLAVOR} \
		${PY_TYPING}

USES=		metaport python:env
USE_PYTHON=	flavors

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>=3.4.0.3:devel/py-singledispatch@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
