PORTNAME=	progressbar
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text progressbar library for python
WWW=		https://github.com/niltonvolpato/python-progressbar

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent pep517
USES=		python

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}progressbar231

.include <bsd.port.mk>
