# $FreeBSD$

PORTNAME=	pyipopt
DISTVERSION=	g20180409
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Use ipopt (an optimization tool) via python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libipopt.so:math/ipopt
RUN_DEPENDS=	${PYNUMPY}

USES=		dos2unix python
USE_GITHUB=	yes
GH_ACCOUNT=	xuy
GH_TAGNAME=	36bcb7f
DOS2UNIX_FILES=	setup.py
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyipopt/pyipoptcore.so

.include <bsd.port.mk>
