PORTNAME=	Mathics3
PORTVERSION=	9.0.0
PORTREVISION=	7
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	General-purpose computer algebra system (CAS)
WWW=		https://mathics.org/

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PY_PILLOW} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}llvmlite>0:devel/py-llvmlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Mathics_Scanner>0:math/py-mathics-scanner \
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}palettable>0:misc/py-palettable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>0:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pympler>0:devel/py-pympler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wordcloud>0:textproc/py-wordcloud@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llvmlite>0:devel/py-llvmlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Mathics_Scanner>0:math/py-mathics-scanner \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>0:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}palettable>0:misc/py-palettable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>0:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pympler>0:devel/py-pympler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyocr>0:graphics/py-pyocr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stopit>0:devel/py-stopit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>0:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wordcloud>0:textproc/py-wordcloud@${PY_FLAVOR} \
		bash:shells/bash
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	${PORTNAME:tl}

USES=		python shebangfix
USE_PYTHON=	cython cython_run noflavors pep517
SHEBANG_GLOB=	*.py
MAKE_ENV+=	USE_CYTHON=yes

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${PORTVERSION}

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
