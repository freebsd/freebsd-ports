# New ports collection makefile for:	system-config-printer-kde
# Date created:		2009-05-04
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	system-config-printer-kde
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdeadmin-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 frontend for system-config-printer

BUILD_DEPENDS=	system-config-printer:${PORTSDIR}/print/system-config-printer \
		${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups \
		${PYTHON_KDE4PREFIX_SITELIBDIR}/PyKDE4/kdeui.so:${PORTSDIR}/devel/kdebindings4-python-pykde4
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:${PORTSDIR}/devel/py-qt4-dbus

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix pimlibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
USE_PYTHON=	2.5+
MD5_FILE=	${PORTSDIR}/sysutils/kdeadmin4/distinfo

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PYTHON_KDE4PREFIX_SITELIBDIR=	${PYTHON_SITELIBDIR:S;${PYTHONBASE};${KDE4_PREFIX};}

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		system-config-printer-kde.py \
		cmake-modules/FindSystemConfigPrinter.py

.include <bsd.port.mk>
