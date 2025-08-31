PORTNAME=	matplotlib
DISTVERSION=	3.8.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plotting library uses a syntax familiar to MATLAB users
WWW=		https://matplotlib.org/

LICENSE=	PSFL

BUILD_DEPENDS=	${PYNUMPY} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=6.2:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0.10:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pybind11:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libqhull_r.so:math/qhull \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}contourpy>=1.0.1:math/py-contourpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.3.1:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=6.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0.10:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiwisolver>=1.0.1:math/py-kiwisolver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.22.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR}

USES=		compiler:c++11-lib gettext gnome localbase pkgconfig python shebangfix uniquefiles:dirs
USE_CXXSTD=	c++14
USE_PYTHON=	pep517

PLIST_SUB=	VER=${PORTVERSION}
PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES

post-extract:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} ${CHMOD} -x

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib -name '*.so' \
		| ${XARGS} ${STRIP_CMD}

post-install-EXAMPLES-on:
	#@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	#${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
