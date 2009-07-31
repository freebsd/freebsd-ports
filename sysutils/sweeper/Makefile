# New ports collection Makefile for:	kdeutils
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeutils
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utilities for the KDE4 integrated X11 Desktop

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		zip.1:${PORTSDIR}/archivers/libzip \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz
RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
KDE4_BUILDENV=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
QT_COMPONENTS=	network gui porting xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_UNSAFE=	yes

MAN1=		ark.1

OPTIONS=	PRINTER_APPLET "Install printer system tray utility" off

.include <bsd.port.pre.mk>

.if defined(WITH_PRINTER_APPLET)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/printer-applet:${PORTSDIR}/print/kdeutils4-printer-applet
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
#disable printer-applet, it comes with print/kdeutils4-printer-applet
	${REINPLACE_CMD} -e '/add_subdirectory.*printer-applet/d' \
		${WRKSRC}/../CMakeLists.txt

.include <bsd.port.post.mk>
