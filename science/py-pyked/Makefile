PORTNAME=	pyked
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1-16
DISTVERSIONSUFFIX=	-gfcccaf8
PORTREVISION=	2
CATEGORIES=	science python
#MASTER_SITES=	PYPI 0.4.1 is broken there
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for manipulating Chemical Kinetics Experimental Data files
WWW=		https://pr-omethe-us.github.io/PyKED/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}Cerberus>=1.0.0:devel/py-cerberus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}habanero>=0.6.0:www/py-habanero@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.7.2:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.0.1:math/py-uncertainties@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.12:devel/py-pyyaml@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	distutils concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	pr-omethe-us
GH_PROJECT=	PyKED

NO_ARCH=	yes

.include <bsd.port.mk>
