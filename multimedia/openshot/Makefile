# Created by: Charlie Kester <corky1951@comcast.net>

PORTNAME=	openshot
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	OpenShot Video Editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libopenshot>=0.2.7:multimedia/libopenshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=0:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:5 python:3.5+ shared-mime-info shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	OpenShot
GH_PROJECT=	${PORTNAME}-qt
USE_PYQT=	pyqt5
USE_PYTHON=	distutils optsuffix
SHEBANG_FILES=	src/language/generate_translations.py\
		src/language/show_translations.py\
		src/language/test_translations.py
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_PORTDOCS=	*

do-build-DOCS-on:
	@(cd ${BUILD_WRKSRC}/doc; if ! ${DO_MAKE_BUILD} html; then \
		(${ECHO_CMD} "===> ${.TARGET} failed unexpectedly.") | ${FMT_80} ; \
		${FALSE}; \
		fi)

do-install-DOCS-on:
	@(cd ${INSTALL_WRKSRC}/doc/_build &&\
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
