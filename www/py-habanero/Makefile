PORTNAME=	habanero
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/sckott/habanero/commit/
PATCHFILES=	e50874fbea1944bd6e4f7bb97743200bdd7c7e9e.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Low-level client for Crossref search API

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
