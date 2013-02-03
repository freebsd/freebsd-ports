# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeadmin
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Admin applications

LATEST_LINK=	${PORTNAME}4

USE_XZ=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT4=	dbus moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

# Disable system-config-printer-kde, it comes with
# print/system-config-printer-kde.
CMAKE_ARGS+=	-DBUILD_system-config-printer-kde:BOOL=Off

OPTIONS_DEFINE=	PRINTER_CONFIG
PRINTER_CONFIG_DESC=	Install printer configuration utility

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPRINTER_CONFIG}
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/system-config-printer-kde/system-config-printer-kde.py:${PORTSDIR}/print/system-config-printer-kde
.endif

.include <bsd.port.mk>
