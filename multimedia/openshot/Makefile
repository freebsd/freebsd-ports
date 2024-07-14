PORTNAME=	openshot
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.1
CATEGORIES=	multimedia

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Video Editor
WWW=		https://www.openshot.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libopenshot>=0.3.3:multimedia/libopenshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=0:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:5 python shared-mime-info shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
GH_PROJECT=	${PORTNAME}-qt
USE_PYQT=	pyqt5 webengine
USE_PYTHON=	distutils optsuffix
SHEBANG_FILES=	src/language/generate_translations.py\
		src/language/show_translations.py\
		src/language/test_translations.py
NO_ARCH=	yes
PLIST_SUB=	VERSION=${DISTVERSION:C/-.+//}

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_BINARY_ALIAS=	sphinx-build=sphinx-build-${PYTHON_VER}
DOCS_PORTDOCS=	*

post-patch:
	${GREP} -r -m 1 -l -e '\blibx264\b' ${WRKSRC}/src/presets ${WRKSRC}/src/windows |\
		${XARGS} ${REINPLACE_CMD} -e 's,[[:<:]]libx264[[:>:]],&rgb,g;' --

do-build-DOCS-on:
	@(cd ${BUILD_WRKSRC}/doc; if ! ${DO_MAKE_BUILD} html; then \
		(${ECHO_CMD} "===> ${.TARGET} failed unexpectedly.") | ${FMT_80} ; \
		${FALSE}; \
		fi)

do-install-DOCS-on:
	@(cd ${INSTALL_WRKSRC}/doc/_build &&\
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} "-not -name \.*")

.include <bsd.port.mk>
