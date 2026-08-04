PORTNAME=	pypandoc
DISTVERSION=	1.17
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Thin wrapper for pandoc
WWW=		https://github.com/bebraw/pypandoc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	pandoc:textproc/hs-pandoc

USES=		python
USE_PYTHON=	pep517 autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
