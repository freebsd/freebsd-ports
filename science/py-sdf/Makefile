PORTNAME=	sdf
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	science cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Simple SDF mesh generation in Python
WWW=		https://github.com/nschloe/meshio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meshio>0:science/py-meshio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	fogleman
GH_TAGNAME=	cee1dac	# No release yet

USES=		python
USE_PYTHON=	distutils

OPTIONS_DEFINE=	EXAMPLES
PORTEXAMPLES=	*

NO_ARCH=	yes

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
