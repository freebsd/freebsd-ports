# $FreeBSD$

PORTNAME=	jsx-lexer
PORTVERSION=	0.0.7
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	JSX lexer for Pygments

LICENSE=	MIT
#LICENSE_FILE=	Not packaged yet in sdist

RUN_DEPENDS=	${PY_PYGMENTS}

USES=		python
USE_GITHUB=	yes # tests not in sdist
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	fcurella

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
