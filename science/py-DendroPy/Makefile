PORTNAME=	DendroPy
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Phylogenetic computing library
WWW=		http://packages.python.org/DendroPy/

LICENSE=	BSD3CLAUSE

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
