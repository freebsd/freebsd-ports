# New ports collection makefile for:	py-qt4-demo
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	demo
PORTVERSION=	20070318
CATEGORIES=	misc devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/Snapshots/PyQt4/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-4-snapshot-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, demo and examples

USE_PYTHON=	yes

OPTIONS=	PYQT4	"Install any missing PyQt4 components" on

OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
EXAMPLESDIR=	${PREFIX}/share/examples/py-qt4

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PYQT4)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtCore.so:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_SITELIBDIR}/PyQt4/QtXml.so:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_SITELIBDIR}/PyQt4/QtAssistant.so:${PORTSDIR}/devel/py-qt4-assistant \
		${PYTHON_SITELIBDIR}/PyQt4/QtOpenGL.so:${PORTSDIR}/x11/py-qt4-opengl \
		${PYTHON_SITELIBDIR}/PyQt4/Qsci.so:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_SITELIBDIR}/PyQt4/QtSql.so:${PORTSDIR}/databases/py-qt4-sql \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtTest.so:${PORTSDIR}/devel/py-qt4-test \
		${PYTHON_SITELIBDIR}/PyQt4/QtDesigner.so:${PORTSDIR}/devel/py-qt4-designer \
		${LOCALBASE}/lib/plugins/designer/libpythonplugin.so:${PORTSDIR}/devel/py-qt4-designerplugin \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:${PORTSDIR}/devel/py-qt4-dbus
.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	${LOCALBASE}/share/doc/py-qt4/pyqt4ref.html:${PORTSDIR}/misc/py-qt4-doc
.endif
.endif

do-build:
	( cd ${WRKSRC}/examples && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py \
		`ls */*.py */*/*.py */*/*/*.py` )

do-install:
	( cd ${WRKSRC} && \
		${MKDIR} -m 0755 ${EXAMPLESDIR} && \
		${CP} -R examples/ ${EXAMPLESDIR} )

.include <bsd.port.post.mk>
