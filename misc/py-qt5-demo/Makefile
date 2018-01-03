# $FreeBSD$

PORTNAME=	demo
PORTVERSION=	${PYQT5_VERSION}
CATEGORIES=	misc devel python
MASTER_SITES=	${MASTER_SITES_PYQT5}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt5-
DISTNAME=	${PYQT_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, Qt demo and examples

DISTINFO_FILE=	${PYQT_DISTINFO_FILE}
NO_BUILD=	yes

PORTSCOUT=	limit:^${PYQT5_VERSION}

USES=		python pyqt:5
USE_PYQT=	core_run dbus_run designer_run \
		designerplugin_run gui_run multimedia_run \
		multimediawidgets_run network_run opengl_run qscintilla2_run \
		sql_run svg_run test_run webkit_run xml_run \
		xmlpatterns_run sip_run qscintilla2_run \
		printsupport_run serialport_run webkitwidgets_run widgets_run
USE_PYTHON=	py3kplist flavors

EXAMPLESDIR=	${PREFIX}/share/examples/py-qt5

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${EXAMPLESDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
