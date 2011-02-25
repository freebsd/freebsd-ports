# New ports collection makefile for: science/veusz
# Date created:		04 Jan 2011
# Whom:			Stas Timokhin <devel@stasyan.com>
#
# $FreeBSD$
#

PORTNAME=	veusz
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	science kde
MASTER_SITES=	http://download.gna.org/veusz/

MAINTAINER=	devel@stasyan.com
COMMENT=	Scientific plotting package

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

LICENSE=	GPLv2

USE_GL=		gl
USE_QT_VER=	4
QT_COMPONENTS=  gui corelib rcc moc uic linguist opengl

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes

.include <bsd.port.mk>
