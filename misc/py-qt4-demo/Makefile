# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	demo
PORTVERSION=	${PYQT4_VERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	misc devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, Qt demo and examples

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}

NO_BUILD=	yes
USES=		python pyqt:4
USE_PYTHON=	concurrent flavors py3kplist

USE_PYQT=	assistant_run core_run dbus_run dbussupport_run declarative_run \
		designer_run designerplugin_run doc_run gui_run help_run \
		multimedia_run network_run opengl_run phonon_run qscintilla2_run \
		script_run scripttools_run sql_run svg_run test_run webkit_run xml_run \
		xmlpatterns_run sip_run qscintilla2_run

do-install:
	${RM} ${WRKSRC}/examples/designer/plugins/plugins.py.orig
	${MKDIR} ${STAGEDIR}${PYQT_EXAMPLEDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${PYQT_EXAMPLEDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYQT_EXAMPLEDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYQT_EXAMPLEDIR}

.include <bsd.port.mk>
