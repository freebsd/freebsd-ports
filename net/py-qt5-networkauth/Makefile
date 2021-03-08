# $FreeBSD$

PORTNAME=	networkauth
PORTVERSION=	${PYQT5_VERSION}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITES_PYQTNETWORKAUTH}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTNETWORKAUTH_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtNetworkAuth module

USES=		python:3.5+ pyqt:5 qt:5
USE_PYQT=	sip_build core gui network widgets
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core gui network networkauth qmake_build
USE_GL+=	gl

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --verbose --no-dist-info \
		-d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-q ${QMAKE} \
		--sip ${SIP} \
		--pyqt-sipdir=${PYQT_SIPDIR}
DESTDIRNAME=	INSTALL_ROOT

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtNetworkAuth API for QScintilla2
API_CONFIGURE_ON=	--apidir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

post-patch:
	${REINPLACE_CMD} -e "s/sip-module/sip-module-${PYTHON_VER}/" ${WRKSRC}/configure.py;
	${REINPLACE_CMD} -e "s/-gui/gui/" ${WRKSRC}/configure.py ${WRKSRC}/pyproject.toml

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5/QtNetworkAuth.so

.include <bsd.port.mk>
