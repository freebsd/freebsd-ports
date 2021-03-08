# $FreeBSD$

PORTNAME=	qutebrowser
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Keyboard-focused browser with a minimal GUI

LICENSE=	GPLv3

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip@${PY_FLAVOR} \
		${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		desktop-file-utils python:3.6+ pyqt:5 qt:5
USE_PYQT=	core opengl printsupport sql widgets qml
USE_QT=		sql-sqlite3
USE_PYTHON=	distutils autoplist noflavors

NO_ARCH=	yes
PLIST_FILES=	share/applications/${PORTNAME}-${PYTHON_VER}.desktop

# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	WEBKIT WEBENGINE
OPTIONS_DEFAULT=	WEBKIT
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE

WEBENGINE_DESC=		WebEngine webpage renderer support

WEBKIT_USE=	PYQT=webkit,webkitwidgets
WEBENGINE_USE=	PYQT=webengine,webchannel

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dataclasses>0:devel/py-dataclasses@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 3900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/org.qutebrowser.qutebrowser.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-${PYTHON_VER}.desktop

.include <bsd.port.post.mk>
