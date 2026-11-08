PORTNAME=	kenlm
DISTVERSION=	0.3.0
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	KenLM: Faster and Smaller Language Model Queries
WWW=		https://kheafield.com/code/kenlm/

LICENSE=	LGPL21

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	pep517 autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
