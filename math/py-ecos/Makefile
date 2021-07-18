PORTNAME=	ecos
DISTVERSION=	2.0.8
CATEGORIES=	math python
#MASTER_SITES=	CHEESESHOP # outdated on PyPI, use GitHub instead
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package for ECOS: Embedded Cone Solver

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9:science/py-scipy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	embotech
GH_PROJECT=	ecos-python
GH_TUPLE=	embotech:ecos:v${DISTVERSION}:ecos/ecos

pre-configure:
	@${ECHO} "__version__=\"$(DISTVERSION)\"" > ${WRKSRC}/src/ecos/version.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_ecos*.so

.include <bsd.port.mk>
