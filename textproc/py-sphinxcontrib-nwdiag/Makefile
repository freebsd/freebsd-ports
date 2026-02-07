PORTNAME=	sphinxcontrib-nwdiag
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Sphinx extension for embedding network-related diagrams
WWW=		https://github.com/blockdiag/${PORTNAME}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nwdiag>=1.0.3:graphics/py-nwdiag@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=2.0:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
