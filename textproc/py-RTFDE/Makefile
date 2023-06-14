PORTNAME=	RTFDE
PORTVERSION=	0.0.2
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

OPTIONS_DEFINE=	LXML

LXML_DESC=	Pythonic binding for the libxml2 and libxslt libraries

LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.6:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.mk>
