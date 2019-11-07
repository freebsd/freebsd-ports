# $FreeBSD$

PORTNAME=	webengine
DISTVERSION=	5.12.1
CATEGORIES=	www devel python
MASTER_SITES=	RIVERBANK/PyQtWebEngine/${DISTVERSION}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	PyQtWebEngine_gpl-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWebEngine module

LICENSE=	GPLv3

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}

USES=		gl python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip_build core gui network printsupport webchannel
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core declarative gui location network printsupport webchannel \
		webengine widgets qmake_build

CONFIGURE_ARGS=	-d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-q ${QMAKE} \
		--sip ${SIP} \
		--pyqt-sipdir ${PYQT_SIPDIR} \
		--verbose
DESTDIRNAME=	INSTALL_ROOT

OPTIONS_DEFINE=		API DEBUG
OPTIONS_DEFAULT=	API
OPTIONS_SUB=		yes

API_DESC=		Install QtWebEngine API for QScintilla2
API_CONFIGURE_ON=	--apidir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

PLIST_SUB=		PYQT_WEBENGINE_VERSION=${DISTVERSION}

post-install-DEBUG-off:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/PyQt5/QtWebEngine*.so

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}

.include <bsd.port.mk>
