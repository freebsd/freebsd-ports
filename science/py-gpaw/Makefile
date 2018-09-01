# $FreeBSD$

PORTNAME=	gpaw
DISTVERSION=	1.4.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DFT and beyond within the projector-augmented wave method in chemistry

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libmpich.so:net/mpich2 \
		libopenblas.so:math/openblas \
		libxc.so:science/libxc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY}

USES=		gettext-runtime localbase python shebangfix
GH_ACCOUNT=	psychopy
USE_PYTHON=	distutils concurrent autoplist
SHEBANG_FILES=	tools/*

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gpaw-python ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_gpaw.so

.include <bsd.port.mk>
