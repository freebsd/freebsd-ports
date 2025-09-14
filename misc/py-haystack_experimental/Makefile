PORTNAME=	haystack_experimental
PORTVERSION=	0.13.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Experimental features for Haystack
WWW=		https://github.com/deepset-ai/haystack-experimental

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filetype>0:devel/py-filetype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}haystack_ai>0:misc/py-haystack_ai@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
