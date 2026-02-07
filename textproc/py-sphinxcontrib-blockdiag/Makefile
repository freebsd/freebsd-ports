PORTNAME=	sphinxcontrib-blockdiag
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Sphinx extension for embedding block diagram
WWW=		https://github.com/blockdiag/${PORTNAME}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blockdiag>=1.5.0:graphics/py-blockdiag@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=2.0:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
