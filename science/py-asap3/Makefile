PORTNAME=	asap3
DISTVERSION=	3.12.8
PORTREVISION=	4
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical potentials for MD with ASE
WWW=		https://wiki.fysik.dtu.dk/asap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libmpich.so:net/mpich # not sure if this is used
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils concurrent autoplist pytest

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_asap.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
