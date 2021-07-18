# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	mathics_pygments
PORTVERSION=	1.0.2
CATEGORIES=	textproc math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Lexer and highlighter for Mathematica/Wolfram Language source code

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}Mathics_Scanner>0:math/py-mathics-scanner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}Mathics_Scanner>0:math/py-mathics-scanner

#USE_GITHUB=	yes
#GH_ACCOUNT=	Mathics3

USES=		python:3.6+
USE_PYTHON=	distutils  noflavors

NO_ARCH=	yes

.include <bsd.port.mk>
