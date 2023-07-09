PORTNAME=	afdko
PORTVERSION=	3.9.6
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adobe Font Development Kit for OpenType
WWW=		https://github.com/adobe-type-tools/afdko

LICENSE=	APACHE20

# print/py-fonttools[woff]: archivers/py-brotli and archivers/py-zopfli
# x11-fonts/py-defcon[pens]: print/py-fontpens
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	afdko>=${PORTVERSION}<${PORTVERSION}_99:x11-fonts/afdko \
		${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.9.0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.0.1:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.10.2:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.9.3:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontpens>=0.1.0:print/py-fontpens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.38.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.9.2:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psautohint>=2.4.0:print/py-psautohint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.64.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufonormalizer>=0.6.1:x11-fonts/py-ufonormalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufoprocessor>=1.9.0:x11-fonts/py-ufoprocessor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zopfli>=0.1.4:archivers/py-zopfli@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/CMakeLists.txt
	@${RM} -r ${WRKSRC}/c/ ${WRKSRC}/cmake/

.include <bsd.port.mk>
