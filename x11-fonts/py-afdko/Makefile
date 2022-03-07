# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	afdko
PORTVERSION=	3.8.1
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adobe Font Development Kit for OpenType

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
# print/py-fonttools[woff]: archivers/py-brotli and archivers/py-zopfli
# x11-fonts/py-defcon[pens]: print/py-fontpens
RUN_DEPENDS=	afdko>=${PORTVERSION}:x11-fonts/afdko \
		${PYTHON_PKGNAMEPREFIX}booleanOperations>=0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.0.1:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontpens>=0.1.0:print/py-fontpens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.8.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psautohint>=0:print/py-psautohint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufonormalizer>=0:x11-fonts/py-ufonormalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufoprocessor>=0:x11-fonts/py-ufoprocessor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zopfli>=0:archivers/py-zopfli@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/CMakeLists.txt
	@${RM} -r ${WRKSRC}/c/ ${WRKSRC}/cmake/

.include <bsd.port.mk>
