# New ports collection Makefile for:	kdeutils
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeutils
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utilities for the KDE4 integrated X11 Desktop

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		qca.2:${PORTSDIR}/devel/qca
RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
USE_PYTHON=	2.5+
KDE4_BUILDENV=	yes
USE_KDE4=	kdeprefix kdehier automoc4 sharedmime \
		kdelibs pimlibs workspace kdebase
QT_COMPONENTS=	network gui porting xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

MAN1=		ark.1

OPTIONS=	7ZIP "Support for 7-Zip archives in Ark" off \
		PRINTER_APPLET "Install printer system tray utility" off \
		RAR "Support for RAR archives in Ark" off \
		ZIP "Support for ZIP archives in Ark" off

.include <bsd.port.options.mk>

.ifdef(WITH_7ZIP)
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

.ifdef(WITH_PRINTER_APPLET)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/printer-applet:${PORTSDIR}/print/kdeutils4-printer-applet
.endif

.ifdef(WITH_ZIP)
RUN_DEPENDS+=	unzip>0:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
.endif

.ifdef(WITH_RAR)
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.if ${ARCH} != "amd64" && ${ARCH} != "ia64" && ${ARCH} != "powerpc" && ${ARCH} != "sparc64"
INSTALL_RAR=	YES
.elif ${ARCH} == "amd64"
.ifndef(HAVE_COMPAT_IA32_KERN)
HAVE_COMPAT_IA32_KERN!=	if ${SYSCTL} -n compat.ia32.maxvmem >/dev/null 2>&1; then ${ECHO_CMD} YES; fi
.endif
.if ${HAVE_COMPAT_IA32_KERN} == "YES"
INSTALL_RAR=	YES
.endif
.endif
.ifdef(INSTALL_RAR)
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.endif
.endif

post-patch:
# Disable printer-applet, it comes with print/kdeutils4-printer-applet.
	${REINPLACE_CMD} -e '/add_subdirectory.*printer-applet/d' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
