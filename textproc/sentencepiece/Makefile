PORTNAME=	sentencepiece
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.99
CATEGORIES=	textproc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unsupervised text tokenizer for Neural Network-based text generation
WWW=		https://github.com/google/sentencepiece

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtcmalloc_minimal.so:devel/google-perftools

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_TESTING_ON=	SPM_BUILD_TEST

.include <bsd.port.mk>
