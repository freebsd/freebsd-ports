# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	rst2html5
PORTVERSION=	1.9.5
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Produces HTML5 documents from reStructuredText sources

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_PATHLIB}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.7:textproc/py-genshi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.14:textproc/py-docutils@${PY_FLAVOR} \
		${PY_PYGMENTS}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
