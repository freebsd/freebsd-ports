# New ports collection makefile for:	py-qt4-demo
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
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
USE_PYTHON=	yes

OPTIONS=	PYQT4	"Install any missing PyQt4 components" off

OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
EXAMPLESDIR=	${PREFIX}/share/examples/py-qt4

.include "../../devel/py-sip/files/bsd.pyqt.mk"
.include <bsd.port.options.mk>

.if !defined(WITHOUT_PYQT4)
RUN_DEPENDS+=	${PKGNAMEPREFIX}core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PKGNAMEPREFIX}gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PKGNAMEPREFIX}network>=${PYQT4_VERSION}:${PORTSDIR}/net/py-qt4-network \
		${PKGNAMEPREFIX}xml>=${PYQT4_VERSION}:${PORTSDIR}/textproc/py-qt4-xml \
		${PKGNAMEPREFIX}assistant>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-assistant \
		${PKGNAMEPREFIX}opengl>=${PYQT4_VERSION}:${PORTSDIR}/x11/py-qt4-opengl \
		${PKGNAMEPREFIX}script>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-script \
		${PKGNAMEPREFIX}sql>=${PYQT4_VERSION}:${PORTSDIR}/databases/py-qt4-sql \
		${PKGNAMEPREFIX}svg>=${PYQT4_VERSION}:${PORTSDIR}/graphics/py-qt4-svg \
		${PKGNAMEPREFIX}test>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-test \
		${PKGNAMEPREFIX}declarative>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-declarative \
		${PKGNAMEPREFIX}designer>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-designer \
		${PKGNAMEPREFIX}designerplugin>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-designerplugin \
		${PKGNAMEPREFIX}dbus>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-dbus \
		${PKGNAMEPREFIX}xmlpatterns>=${PYQT4_VERSION}:${PORTSDIR}/textproc/py-qt4-xmlpatterns \
		${PKGNAMEPREFIX}help>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-help \
		${PKGNAMEPREFIX}webkit>=${PYQT4_VERSION}:${PORTSDIR}/www/py-qt4-webkit \
		${PKGNAMEPREFIX}phonon>=${PYQT4_VERSION}:${PORTSDIR}/multimedia/py-qt4-phonon
.endif

do-build:
	cd ${WRKSRC}/examples &&\
		${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py\
		`ls */*.py */*/*.py */*/*/*.py`

do-install:
	${RM} -f ${WRKSRC}/examples/designer/plugins/plugins.py.orig
	${RM} -f ${WRKSRC}/examples/activeqt/webbrowser/webbrowser.py.orig
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

.include <bsd.port.mk>
