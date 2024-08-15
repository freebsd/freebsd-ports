PORTNAME=	cu2qu
PORTVERSION=	1.6.7p2
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI/source/c/cu2qu
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/.post/}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Cubic-to-quadratic bezier curve conversion
WWW=		https://github.com/googlefonts/cu2qu

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defcon>=0.6.0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=3.32.0:print/py-fonttools@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
