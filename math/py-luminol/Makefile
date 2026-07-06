PORTNAME=	luminol
DISTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight python library for time series data analysis
WWW=		https://github.com/LinkedInAttic/naarad

LICENSE=	APACHE20

DEPRECATED=		Upstream last activity was in 2016, and the project has been moved to the LinkedInAttic GitHub account.
EXPIRATION_DATE=	2026-07-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
