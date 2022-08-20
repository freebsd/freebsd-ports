PORTNAME=	markdown-include
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides an "include" function for Markdown

LICENSE=	GPLv3+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	cmacmackin
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
