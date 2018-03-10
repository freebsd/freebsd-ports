# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	scimath
PORTVERSION=	4.1.2
PORTREVISION=	4
CATEGORIES=	science math python
MASTER_SITES=	http://www.enthought.com/repo/ets/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Scientific and Mathematical calculations

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=3.6.0:devel/py-traits@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
