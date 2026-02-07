PORTNAME=	mathics_pygments
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	textproc math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Lexer and highlighter for Mathematica/Wolfram Language source code
WWW=		https://mathics.org/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}Mathics_Scanner>0:math/py-mathics-scanner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}types_pygments>0:devel/py-types-Pygments@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}Mathics_Scanner>0:math/py-mathics-scanner

#USE_GITHUB=	yes
#GH_ACCOUNT=	Mathics3

USES=		python
USE_PYTHON=	distutils  noflavors

NO_ARCH=	yes

.include <bsd.port.mk>
