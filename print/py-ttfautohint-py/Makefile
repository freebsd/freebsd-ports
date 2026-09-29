PORTNAME=	ttfautohint-py
PORTVERSION=	0.6.1
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ttfautohint_py-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for ttfautohint
WWW=		https://github.com/fonttools/ttfautohint-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libttfautohint.so:print/ttfautohint

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/src/c/

.include <bsd.port.mk>
