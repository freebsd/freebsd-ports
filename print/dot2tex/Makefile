PORTNAME=	dot2tex
PORTVERSION=	2.11.3
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Graphviz to LaTeX converter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=1.4.8:devel/py-pyparsing@${PY_FLAVOR} \
		dot:graphics/graphviz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist concurrent

# Enable this before running test target
# bsd.tex.mk doesnt support :test (only) depends
#USE_TEX=	latex

GH_ACCOUNT=	kjellmf

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose

.include <bsd.port.mk>
