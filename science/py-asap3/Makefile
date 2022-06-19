PORTNAME=	asap3
DISTVERSION=	3.12.8
CATEGORIES=	science python # chemistry
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical potentials for MD with ASE

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libmpich.so:net/mpich # not sure if this is used
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR}

USES=		localbase python:3.7+
USE_PYTHON=	distutils concurrent autoplist pytest

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_asap.cpython-38.so

.include <bsd.port.mk>
