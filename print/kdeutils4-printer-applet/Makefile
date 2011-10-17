# New ports collection makefile for:	kdeutils4-printer-applet
# Date created:		2009-05-04
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	printer-applet
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kdeutils-
DISTNAME=	kdeutils-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer system tray utility for KDE4

RUN_DEPENDS=	system-config-printer:${PORTSDIR}/print/system-config-printer \
		${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups

USE_KDE4=	kdehier kdelibs kdeprefix pykde4 pykdeuic4 automoc4
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
DISTINFO_FILE=	${PORTSDIR}/misc/kdeutils4/distinfo
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DINSTALL_PRINTER_APPLET:BOOL=ON \
		-DBUILD_kgpg:BOOL=OFF # Avoid checking for kdepimlibs.

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		printer-applet-printers.ui \
		printer-applet.py \
		cmake-modules/FindSystemConfigPrinter.py

.include <bsd.port.mk>
