PORTNAME=	tiktoken
PORTVERSION=	0.9.0
PORTREVISION=	5
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast BPE tokeniser for use with OpenAI's models
WWW=		https://github.com/openai/tiktoken

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=62.4:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.5.2:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>=2022.1.18:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR}

USES=		cargo python:3.9+
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no

OPTIONS_DEFINE=	BLOBFILE
BLOBFILE_DESC=	Blob file support

BLOBFILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blobfile>=2:net/py-blobfile@${PY_FLAVOR}

.include <bsd.port.mk>
