PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding and handling crystal symmetries (python binding)
WWW=		https://atztogo.github.io/spglib/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libsymspg.so:science/spglib
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake python
USE_PYTHON=	flavors pytest # tests fail to run, see https://github.com/spglib/spglib/issues/192
USE_GITHUB=	yes

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

WRKSRC_SUBDIR=	python

post-patch:
	#@cd ${WRKSRC} && ${RLN} ../test .
	@cd ${WRKSRC} && ${CP} -r ../test .

.include <bsd.port.mk>
