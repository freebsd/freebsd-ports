# Created by: Alex Dupre <ale@FreeBSD.org>

PORTNAME=	httpie
PORTVERSION=	2.5.0
CATEGORIES=	www
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Command line HTTP client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.6.0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.5.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.9.1:www/py-requests-toolbelt@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
