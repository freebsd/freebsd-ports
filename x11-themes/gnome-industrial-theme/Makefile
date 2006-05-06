# New ports collection makefile for:	gnome-industrial-theme
# Date created:		18 August 2003
# Whom:			Frank Ruell
#
# $FreeBSD$
#

PORTNAME=	gnome-industrial-theme
PORTVERSION=	0.2.29
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://ftp.ximian.com/pub/xd2/redhat-9-i386/source/ \
		${MASTER_SITE_GENTOO:S,%SUBDIR%,distfiles,}
DISTNAME=	ximian-artwork-${PORTVERSION}-${XIMIAN_SUBVERSION}.ximian.${XIMIAN_DISTVERSION}.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	stoerte@dreamwarrior.net
COMMENT=	Slick GNOME2 theme from Ximian

EXTRACT_DEPENDS=rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
BUILD_DEPENDS=	${X11BASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libindustrial.so:${PORTSDIR}/x11-themes/gnome-themes-extras
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack libgnomeui

WRKSRC=		${WRKDIR}/ximian-artwork-${PORTVERSION}

PNG_DIRS=	Industrial/192x192/apps \
		Industrial/192x192/filesystems \
		Industrial/24x24/apps \
		Industrial/32x32/apps \
		Industrial/48x48/apps \
		Industrial/48x48/devices \
		Industrial/48x48/emblems \
		Industrial/48x48/filesystems \
		Industrial/48x48/mimetypes \
		Industrial/72x72/filesystems \
		Industrial/96x96/filesystems \

SVG_DIRS=	Industrial/scalable/devices \
		Industrial/scalable/filesystems

ICON_DIRS=	Industrial/48x48/filesystems \
		Industrial/scalable/filesystems

XIMIAN_SUBVERSION=	0
XIMIAN_DISTVERSION=	6.3

.if defined(WITH_XMMS)
BUILD_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
PLIST_SUB+=	XMMS="@comment "
.endif

pre-everything::
.if !defined(WITH_XMMS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "By default only the GNOME2 theme will be installed."
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_XMMS=yes   Install also matching xmms theme"
	@${ECHO_MSG} ""
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && rpm2cpio.pl ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}\
		| ${CPIO} -i ximian-artwork-${PORTVERSION}.tar.gz 2>/dev/null \
		&& ${GZIP_CMD} -dc ximian-artwork-${PORTVERSION}.tar.gz \
		| ${TAR} -xf - && ${RM} ximian-artwork-${PORTVERSION}.tar.gz);\
		then \
			exit 1; \
	fi

do-patch:
	@${DO_NADA}

post-patch:
	@${RM} ${WRKSRC}/icons/Industrial/48x48/emblems/emblem-ximian.png
	@${SED} 's|^_||g' ${WRKSRC}/index.theme.in > ${WRKSRC}/index.theme
	@${SED} 's|^_||g' ${WRKSRC}/icons/Industrial/index.theme.in > ${WRKSRC}/icons/Industrial/index.theme

do-install:
.for d in ${PNG_DIRS}
	@${MKDIR} ${PREFIX}/share/icons/${d}
	@${INSTALL_DATA} ${WRKSRC}/icons/${d}/*.png ${PREFIX}/share/icons/${d}
.endfor

.for d in ${SVG_DIRS}
	@${MKDIR} ${PREFIX}/share/icons/${d}
	@${INSTALL_DATA} ${WRKSRC}/icons/${d}/*.svg ${PREFIX}/share/icons/${d}
.endfor

.for d in ${ICON_DIRS}
	@${INSTALL_DATA} ${WRKSRC}/icons/${d}/*.icon ${PREFIX}/share/icons/${d}
.endfor

	@${INSTALL_DATA} ${WRKSRC}/icons/Industrial/index.theme ${PREFIX}/share/icons/Industrial

	@${MKDIR} ${PREFIX}/share/gnome/themes/Industrial/metacity-1
	@${INSTALL_DATA} ${WRKSRC}/metacity/metacity-theme-1.xml ${PREFIX}/share/gnome/themes/Industrial/metacity-1
	@${INSTALL_DATA} ${WRKSRC}/index.theme ${PREFIX}/share/themes/Industrial

.if defined(WITH_XMMS)
	@${MKDIR} ${PREFIX}/share/xmms/Skins/Industrial
	@${INSTALL_DATA} ${WRKSRC}/xmms/*.bmp ${PREFIX}/share/xmms/Skins/Industrial
	@${INSTALL_DATA} ${WRKSRC}/xmms/pledit.txt ${PREFIX}/share/xmms/Skins/Industrial
	@${INSTALL_DATA} ${WRKSRC}/xmms/viscolor.txt ${PREFIX}/share/xmms/Skins/Industrial
.endif

.include <bsd.port.mk>
