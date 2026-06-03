PORTNAME=	asap3
DISTVERSION=	3.13.11
PORTREVISION=	2
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical potentials for MD with ASE
WWW=		https://wiki.fysik.dtu.dk/asap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libmpich.so:net/mpich # not sure if this is used
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ase>=3.24.0:science/py-ase@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils concurrent autoplist pytest

post-patch:
	@${REINPLACE_CMD} -e "s/license = 'LGPL-3.0'/license = {text = 'LGPL-3.0'}/" \
		-e "/^license-files/d" \
		${WRKSRC}/pyproject.toml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_asap.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
