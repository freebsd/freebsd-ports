PORTNAME=	pdf2docx
DISTVERSION=	0.5.8
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and applicaton to convert pdf to docx
WWW=		https://github.com/dothinking/pdf2docx

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fire>=0.3.0:devel/py-fire@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyMuPDF>=1.19.0:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.24.0:print/py-fonttools@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}python-docx>=0.8.10:textproc/py-python-docx@${PY_FLAVOR} \
		opencv>0:graphics/opencv
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # 2 tests fail, see https://github.com/ArtifexSoftware/pdf2docx/issues/276

NO_ARCH=	yes

.include <bsd.port.mk>
