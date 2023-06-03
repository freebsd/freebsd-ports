PORTNAME=	sentencepiece
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.99
CATEGORIES=	textproc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unsupervised text tokenizer for Neural Network-based text generation
WWW=		https://github.com/google/sentencepiece

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libsentencepiece.so:textproc/sentencepiece

USES=		compiler:c++17-lang pkgconfig python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	google

WRKSRC_SUBDIR=	python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
