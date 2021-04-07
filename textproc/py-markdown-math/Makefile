PORTNAME=	markdown-math
PORTVERSION=	0.6
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Math formulas support to Python-Markdown

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=2.0.3:textproc/py-markdown@${PY_FLAVOR}

USES=	python:3.2+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
