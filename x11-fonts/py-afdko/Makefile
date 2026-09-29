PORTNAME=	afdko
PORTVERSION=	5.0.1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI \
		https://github.com/adobe-type-tools/afdko/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adobe Font Development Kit for OpenType
WWW=		https://adobe-type-tools.github.io/afdko/ \
		https://github.com/adobe-type-tools/afdko

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.9.0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.10.2:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.9.3:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.59.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=6.0.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.66.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufonormalizer>=0.6.2:x11-fonts/py-ufonormalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufoprocessor>=1.13.1:x11-fonts/py-ufoprocessor@${PY_FLAVOR}
# x11-fonts/py-defcon[pens]: print/py-fontpens
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fontpens>=0.1.0:print/py-fontpens@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-patch:
	@${RM} ${WRKSRC}/CMakeLists.txt
	@${RM} -r ${WRKSRC}/c/ ${WRKSRC}/cmake/ ${WRKSRC}/cython/
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third_party/

.include <bsd.port.post.mk>
