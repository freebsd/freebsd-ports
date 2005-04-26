# New ports collection makefile for:	linux-gtk-bluecurve-theme
# Date created:			19 Jun 2004
# Whom:				Jean-Yves lefort
#
# $FreeBSD$
#

PORTNAME=		linux-gtk-bluecurve-theme
PORTVERSION=		0.73
PORTREVISION=		1
CATEGORIES=		x11-themes
MASTER_SITES=		ftp://fr.rpmfind.net/linux/redhat/9/en/os/${MACHINE_ARCH}/RedHat/RPMS/
DISTFILES=		redhat-artwork-${PORTVERSION}-1.${MACHINE_ARCH}.rpm
DIST_SUBDIR=		rpm

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		Bluecurve theme for GTK1 and GTK2 from RedHat 8.0 (Linux version)

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

NO_WRKSUBDIR=		yes
USE_LINUX_PREFIX=	yes
NO_BUILD=		yes
USE_REINPLACE=		yes
ONLY_FOR_ARCHS=		i386

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR}; rpm2cpio.pl ${_DISTDIR}/${DISTFILES} | ${CPIO} -id --quiet

post-patch:
	@${REINPLACE_CMD} -e 's|include "iconrc"||' \
		${WRKSRC}/usr/share/themes/Bluecurve/gtk-2.0/gtkrc

do-install:
	${MKDIR} ${PREFIX}/usr/share/themes/Bluecurve
	${MKDIR} ${PREFIX}/usr/lib/gtk-2.0/2.2.0/engines
	${MKDIR} ${PREFIX}/usr/share/themes/Bluecurve/gtk-2.0
	${INSTALL_DATA} ${WRKSRC}/usr/lib/gtk-2.0/2.2.0/engines/libbluecurve.so ${PREFIX}/usr/lib/gtk-2.0/2.2.0/engines
	${INSTALL_DATA} ${WRKSRC}/usr/share/themes/Bluecurve/gtk-2.0/gtkrc ${PREFIX}/usr/share/themes/Bluecurve/gtk-2.0
	${MKDIR} ${PREFIX}/usr/lib/gtk/themes/engines
	${INSTALL_DATA} ${WRKSRC}/usr/lib/gtk/themes/engines/libbluecurve.so ${PREFIX}/usr/lib/gtk/themes/engines
	${MKDIR} ${PREFIX}/usr/share/themes/Bluecurve/gtk
	${INSTALL_DATA} ${WRKSRC}/usr/share/themes/Bluecurve/gtk/gtkrc ${PREFIX}/usr/share/themes/Bluecurve/gtk

.include <bsd.port.mk>
