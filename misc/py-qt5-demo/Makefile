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

USES=		python:3.5+ pyqt:5
USE_PYQT=	core_run dbus_run designer_run \
		designerplugin_run gui_run multimedia_run \
		multimediawidgets_run network_run opengl_run \
		printsupport_run qscintilla2_run serialport_run sql_run \
		sip_run svg_run test_run webkit_run webkitwidgets_run \
		widgets_run xml_run xmlpatterns_run
		
USE_PYTHON=	concurrent flavors py3kplist
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PYQT_EXAMPLEDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${PYQT_EXAMPLEDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYQT_EXAMPLEDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYQT_EXAMPLEDIR}

.include <bsd.port.mk>
