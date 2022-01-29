PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.3
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding and handling crystal symmetries (python binding)

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes

WRKSRC_SUBDIR=	python

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spglib/_spglib*.so

.include <bsd.port.mk>
