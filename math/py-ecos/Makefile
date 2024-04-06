PORTNAME=	ecos
DISTVERSION=	2.0.13
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package for ECOS: Embedded Cone Solver
WWW=		https://www.embotech.com/ECOS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

pre-configure:
	@${ECHO} "__version__=\"$(DISTVERSION)\"" > ${WRKSRC}/src/ecos/version.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_ecos*.so

.include <bsd.port.mk>
