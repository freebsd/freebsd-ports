# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	kaa-base
PORTVERSION=	0.6.0
PORTREVISION=	9
CATEGORIES=	multimedia python
MASTER_SITES=	SF/freevo/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository

LIB_DEPENDS=	libglib-2.0.so:${PORTSDIR}/devel/glib20
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
