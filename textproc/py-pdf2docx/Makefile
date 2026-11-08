PORTNAME=	pdf2docx
DISTVERSION=	0.5.13
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and applicaton to convert pdf to docx
WWW=		https://github.com/dothinking/pdf2docx

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fire>=0.3.0:devel/py-fire@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf>=1.19.0:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.24.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>=0.8.10:textproc/py-python-docx@${PY_FLAVOR} \
		opencv>0:graphics/opencv

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # ruff tests skipped, see https://github.com/ArtifexSoftware/pdf2docx/issues/276

NO_ARCH=	yes

MAKE_ENV+=	PDF2DOCX_VERSION=${DISTVERSION}

# tests as of 0.5.13: 2 passed, 2 warnings in 24.16s

.include <bsd.port.mk>
