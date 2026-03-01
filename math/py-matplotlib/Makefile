PORTNAME=	matplotlib
DISTVERSION=	3.10.8
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Plotting library uses a syntax familiar to MATLAB users
WWW=		https://matplotlib.org/

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.13.2:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR}
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libqhull_r.so:math/qhull
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}contourpy>=1.0.1:math/py-contourpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cycler>=0.10:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.22.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiwisolver>=1.3.1:math/py-kiwisolver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7:devel/py-python-dateutil@${PY_FLAVOR}

USES=				compiler:c++17-lang gettext gnome localbase \
				pkgconfig python shebangfix uniquefiles:dirs
USE_CXXSTD=			c++17
USE_PYTHON=			autoplist pep517
PEP517_BUILD_CONFIG_SETTING=	-Csetup-args="-Dsystem-freetype=true" \
				-Csetup-args="-Dsystem-qhull=true"

PLIST_SUB=	VER=${PORTVERSION}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	@${FIND} ${WRKSRC} -name '*.py' | \
		${XARGS} ${CHMOD} -x

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/matplotlib -name '*.so' | \
		${XARGS} ${STRIP_CMD}

post-install-EXAMPLES-on:
	#@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	#${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
