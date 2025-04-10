PORTNAME=	sentencepiece
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	textproc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unsupervised text tokenizer for Neural Network-based text generation
WWW=		https://github.com/google/sentencepiece

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_TESTING_ON=	SPM_BUILD_TEST

OPTIONS_DEFINE=		GPERFTOOLS # this seems to cause this error in llama-cpp's convert_hf_to_gguf.py: Attempt to free invalid pointer 0x1ef160aa2f80, see https://github.com/google/sentencepiece/issues/1105

GPERFTOOLS_CMAKE_BOOL=	SPM_ENABLE_TCMALLOC
GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools

.include <bsd.port.mk>
