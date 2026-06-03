PORTNAME=	nano-pdf
PORTVERSION=	0.2.1
CATEGORIES=	textproc
MASTER_SITES=	PYPI
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI tool to edit PDF slides using natural language with Gemini
WWW=		https://github.com/gavrielc/Nano-PDF

LICENSE=	MIT

USES=		python
USE_PYTHON=	pep517 autoplist

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-genai>0:misc/py-google-genai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf2image>0:graphics/py-pdf2image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf>0:print/py-pypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytesseract>0:graphics/py-pytesseract@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0:devel/py-typer@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
