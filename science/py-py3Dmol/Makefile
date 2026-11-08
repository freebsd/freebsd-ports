PORTNAME=	py3Dmol
DISTVERSION=	2.5.5
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py3dmol-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IPython interface for embedding 3Dmol.js views
WWW=		https://3dmol.csb.pitt.edu/

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
