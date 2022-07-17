PORTNAME=	kpLib
DISTVERSION=	1.0.5
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding optimal Generalized Monkhorst-Pack k-points grid

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.1.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen>=2021.3.9:science/py-pymatgen@${PY_FLAVOR}

USES=		compiler:c++17-lang localbase python
USE_LDCONFIG=	yes

USE_PYTHON=	distutils concurrent autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/kpLib/lib${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
