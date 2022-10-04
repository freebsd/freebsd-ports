PORTNAME=	gemmi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.7
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Macromolecular crystallography library and utilities
WWW=		https://gemmi.readthedocs.io/en/latest/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		pybind11>=2.6:devel/pybind11

USES=		cmake compiler:c++17-lang python

USE_GITHUB=	yes
GH_ACCOUNT=	project-gemmi

CMAKE_ON=	USE_PYTHON

PLIST_FILES=	${PYTHON_SITELIBDIR}/gemmi${PYTHON_EXT_SUFFIX}.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover -v tests/

.include <bsd.port.mk>
