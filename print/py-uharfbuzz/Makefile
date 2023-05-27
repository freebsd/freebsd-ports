PORTNAME=	uharfbuzz
PORTVERSION=	0.37.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Streamlined Cython bindings for the harfbuzz shaping engine
WWW=		https://github.com/harfbuzz/uharfbuzz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	harfbuzz>=7.3.0:print/harfbuzz \
		${PYTHON_PKGNAMEPREFIX}setuptools>=36.4:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=2.1:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang python:3.6+ zip
USE_PYTHON=	autoplist concurrent cython pep517

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/setup.py ${WRKSRC}/src/uharfbuzz/_harfbuzz.cpp
	@${RM} ${WRKSRC}/src/uharfbuzz/_harfbuzz.cpp
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/harfbuzz/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
