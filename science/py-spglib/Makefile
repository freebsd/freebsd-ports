PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding and handling crystal symmetries (python binding)
WWW=		https://atztogo.github.io/spglib/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/spglib/spglib/issues/192
USE_GITHUB=	yes

WRKSRC_SUBDIR=	python

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spglib/_spglib*.so

.include <bsd.port.mk>
