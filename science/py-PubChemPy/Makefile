PORTNAME=	PubChemPy
DISTVERSION=	1.0.5
CATEGORIES=	science python
MASTER_SITES=	PYPI
MASTER_SITE_SUBDIR=	source/p/pubchempy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pubchempy-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple Python wrapper around the PubChem PUG REST API
WWW=		https://github.com/mcs07/PubChemPy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
