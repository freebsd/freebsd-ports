# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	scimath
PORTVERSION=	4.2.0
CATEGORIES=	science math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Scientific and Mathematical calculations

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
