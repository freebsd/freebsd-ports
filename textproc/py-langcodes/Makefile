PORTNAME=	langcodes
PORTVERSION=	3.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for labeling human languages with IETF language tags
WWW=		https://github.com/rspeer/langcodes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DATA
OPTIONS_DEFAULT=DATA
DATA_DESC=	Use supplementary language data

DATA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}language-data>=1.1<2:textproc/py-language-data@${PY_FLAVOR}

.include <bsd.port.mk>
