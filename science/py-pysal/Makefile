# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pysal
PORTVERSION=	1.14.3
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySAL-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library of spatial analysis functions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.3,1:math/py-numpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.11:science/py-scipy@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

post-patch:
	@${REINPLACE_CMD} -e '/check_stable=/ s|True|False|' ${WRKSRC}/pysal/config.py

.include <bsd.port.mk>
