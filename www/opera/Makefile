# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_BUILD}
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/${MASTER_SITES_VER_PATH}/ \
		ftp://opera.inode.at/${MASTER_SITES_VER_PATH}/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/${MASTER_SITES_VER_PATH}/ \
		http://ftp.ucr.ac.cr/WWW/opera/${MASTER_SITES_VER_PATH}/ \
		http://www.microrpm.ca/pub/opera/${MASTER_SITES_VER_PATH}/ \
		http://opera.eurenet.net/${MASTER_SITES_VER_PATH}/ \
		ftp://opera.ftp.fu-berlin.de/${MASTER_SITES_VER_PATH}/ \
		http://ftp.ntua.gr/pub/www/Opera/${MASTER_SITES_VER_PATH}/ \
		ftp://ftp.wayne.edu/opera/${MASTER_SITES_VER_PATH}/ \
		http://mirrors.dedipower.com/opera/${MASTER_SITES_VER_PATH}/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.opera.com/${MASTER_SITES_VER_PATH}/ \
		http://opera.nedmirror.nl/${MASTER_SITES_VER_PATH}/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/${MASTER_SITES_VER_PATH}/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/${MASTER_SITES_VER_PATH}&,}/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.${ARCH}.freebsd

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Blazingly fast, full-featured, standards-compliant browser, devel version

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		pcre.0:${PORTSDIR}/devel/pcre \
		png.6:${PORTSDIR}/graphics/png \
		pthread-stubs.0:${PORTSDIR}/devel/libpthread-stubs \
		streamanalyzer.0:${PORTSDIR}/deskutils/strigi \
		streams.0:${PORTSDIR}/deskutils/strigi \
		xcb-render-util.0:${PORTSDIR}/x11/xcb-util \
		xcb-render.0:${PORTSDIR}/x11/libxcb \
		xcb.2:${PORTSDIR}/x11/libxcb

LICENSE=	LGPL20

OPERA_VER=	10.61
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_ICONV=	yes
MANCOMPRESSED=	yes
USE_XLIB=	ice pixman sm x11 xau xcomposite xcursor xdamage xdmcp \
		xext xfixes xft xi xinerama xpm xrandr xrender xtst
USE_GSTREAMER=	yes
USE_GETTEXT=	yes
OPERA_BUILD=	6430
MASTER_SITES_VER_PATH=	unix/${OPERA_VER:S/.//}

USE_BZIP2=	yes

MAN1=		${PORTNAME}-widget-manager.1 \
		${PORTNAME}.1

NO_BUILD=	yes

OPTIONS=	GTK "Use GTK backend" off \
		QT4 "Use Qt4 backend" off \
		KDE4 "Use KDE4 backend" off

.include <bsd.port.options.mk>

.if defined(WITH_GTK)
USE_GNOME=	atk gtk20 glib20 pango libxml2
USE_FPC=	cairo
.endif

.if defined(WITH_QT4)
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui network svg xml
.endif

.if defined(WITH_KDE4)
USE_KDE4=	kdelibs
.endif

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

OPERA_ARCH=	${ARCH:S,i386,intel,}

.if ${OSVERSION} < 700000
IGNORE=		Only for FreeBSD 7.x and higher
.endif

do-install:
	@${MV} ${WRKSRC}/share/man ${WRKSRC}/man
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1.gz ${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}-widget-manager.1.gz ${MANPREFIX}/man/man1/
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/install
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/install
	@(cd ${WRKSRC} && ./install --text --system --unattended)
	@${REINPLACE_CMD} -e 's|/usr/X11R6/lib/browser_plugins|${LOCALBASE}/lib/browser_plugins/symlinks/opera|g' \
		${DATADIR}/defaults/pluginpath.ini
	@${RM} ${DATADIR}/defaults/pluginpath.ini.bak

.include <bsd.port.post.mk>
