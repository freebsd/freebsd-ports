# Created by: Ju Pengfei <ju.pengfei@gmail.com>
# $FreeBSD$

PORTNAME=	numexpr
PORTVERSION=	2.2.2
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast numerical array expression evaluator for Python and NumPy

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
