PORTNAME=	RTFDE
DISTVERSION=	0.1.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Library for extracting HTML content from RTF encapsulated HTML
WWW=		https://github.com/seamustuohy/RTFDE

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lark>=0.11:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oletools>=0.56:devel/py-oletools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
