# $FreeBSD$

PORTNAME=	chempy
DISTVERSION=	0.7.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package useful useful for solving problems in chemistry

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bokeh>=0.11.1:www/py-bokeh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PuLP>=1.6.8:math/py-PuLP@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyneqsys>=0.5.4:math/py-pyneqsys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyodesys>=0.12.3:math/py-pyodesys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.3:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantities>=0.12.1:science/py-quantities@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sym>=0.3.4:math/py-sym@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.1.1:math/py-sympy@${PY_FLAVOR} \
		${NUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
