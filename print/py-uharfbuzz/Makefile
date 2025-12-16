PORTNAME=	uharfbuzz
PORTVERSION=	0.53.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Streamlined Cython bindings for the harfbuzz shaping engine
WWW=		https://github.com/harfbuzz/uharfbuzz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	harfbuzz>=12.1.0:print/harfbuzz \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=36.4:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=2.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist concurrent cython pep517

MAKE_ENV=	CYTHON_ANNOTATE=0 CYTHON_LINETRACE=0 USE_SYSTEM_LIBS=1

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/harfbuzz/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
