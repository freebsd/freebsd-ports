PORTNAME=	snowballstemmer
PORTVERSION=	2.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Snowball stemming library collection for Python
WWW=		https://snowballstem.org/ \
		https://github.com/snowballstem/snowball

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PYSTEMMER
OPTIONS_DEFAULT=PYSTEMMER
PYSTEMMER_DESC=	Use PyStemmer to accelerate

PYSTEMMER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pystemmer>=0:textproc/py-pystemmer@${PY_FLAVOR}

.include <bsd.port.mk>
