# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	sphinx-inline-tabs
PORTVERSION=	2021.4.11b9
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_inline_tabs-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add inline tabbed content to your Sphinx documentation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=3,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
