PORTNAME=	pybtex
PORTVERSION=	0.24.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BibTeX-compatible bibliography processor in Python
WWW=		https://pybtex.org/ \
		https://bitbucket.org/pybtex-devs/pybtex/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}latexcodec>=1.0.4:textproc/py-latexcodec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.01:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
