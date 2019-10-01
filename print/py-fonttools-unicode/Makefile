# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	3.44.0
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-unicode

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dependencies for unicode functionality of FontTools

USES=		metaport python:env
USE_PYTHON=	flavors

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}unicodedata2>=12.0.0:devel/py-unicodedata2@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
