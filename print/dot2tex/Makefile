PORTNAME=	dot2tex
PORTVERSION=	2.11.3
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Graphviz to LaTeX converter
WWW=		https://github.com/kjellmf/dot2tex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=1.4.8:devel/py-pyparsing@${PY_FLAVOR} \
		dot:graphics/graphviz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python tex
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist concurrent

USE_TEX=	latex:test

GH_ACCOUNT=	kjellmf

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose

.include <bsd.port.mk>
