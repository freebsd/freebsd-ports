# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	demo
PORTVERSION=	${PYQT4_VERSION}
PORTEPOCH=	1
CATEGORIES=	misc devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, Qt demo and examples

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}

NO_BUILD=	yes
USES=		python pyqt:4

EXAMPLESDIR=	${PREFIX}/share/examples/py-qt4

USE_PYQT=	assistant_run core_run dbus_run dbussupport_run declarative_run \
		designer_run designerplugin_run doc_run gui_run help_run \
		multimedia_run network_run opengl_run phonon_run qscintilla2_run \
		script_run scripttools_run sql_run svg_run test_run webkit_run xml_run \
		xmlpatterns_run sip_run qscintilla2_run

do-install:
	${RM} -f ${WRKSRC}/examples/designer/plugins/plugins.py.orig
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${EXAMPLESDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
