PORTNAME=	pdfminer.six
DISTVERSION=	20240706
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	PDF parser and analyzer
WWW=		https://github.com/pdfminer/pdfminer.six

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning<3:devel/py-setuptools-git-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>0:textproc/py-charset-normalizer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography distutils

CONFLICTS_INSTALL=	py??-pdfminer py??-pdfminer3k
NO_ARCH=		yes

OPTIONS_DEFINE=		IMAGE
OPTIONS_DEFAULT=	IMAGE

IMAGE_DESC=	Enable support for image extraction
IMAGE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

post-extract:
	@cd ${WRKSRC} && ${MV} tools/dumppdf.py tools/dumppdf
	@cd ${WRKSRC} && ${MV} tools/pdf2txt.py tools/pdf2txt

.include <bsd.port.mk>
