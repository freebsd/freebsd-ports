PORTNAME=	orange3-educational
DISTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	misc education python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange add-on: widgets for machine learning and data mining
WWW=		https://github.com/biolab/orange3-educational

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	biolab

NO_ARCH=	yes

.include <bsd.port.mk>
