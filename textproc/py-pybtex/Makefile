PORTNAME=	pybtex
PORTVERSION=	0.26.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BibTeX-compatible bibliography processor in Python
WWW=		https://pybtex.org/ \
		https://codeberg.org/pybtex/pybtex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}latexcodec>=1.0.4:textproc/py-latexcodec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.01:devel/py-pyyaml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	src/pybtex/charwidths/make_charwidths.py

.include <bsd.port.mk>
