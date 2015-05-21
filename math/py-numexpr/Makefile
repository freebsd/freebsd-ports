# Created by: Ju Pengfei <ju.pengfei@gmail.com>
# $FreeBSD$

PORTNAME=	numexpr
PORTVERSION=	2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast numerical array expression evaluator for Python and NumPy

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	autoplist distutils
USES=		python

GH_ACCOUNT=	pydata
USE_GITHUB=	yes

.include <bsd.port.mk>
