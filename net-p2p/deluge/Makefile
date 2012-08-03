# New ports collection makefile for:	deluge
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deluge
PORTVERSION=	1.3.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.deluge-torrent.org/source/
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Bittorrent client using Python, GTK+2, and libtorrent-rasterbar

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0.18:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}libtorrent-rasterbar>=0.15.1:${PORTSDIR}/net-p2p/libtorrent-rasterbar-15-python \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.8:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}chardet>=1.0.1:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}mako>=0.2.5:${PORTSDIR}/textproc/py-mako

USE_RC_SUBR=	deluged
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

USE_XZ=		yes
WANT_GNOME=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_PYTHON=	-2.7
USE_TWISTED_RUN=	web
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_BUILD_TARGET=	build bdist_egg

OPTIONS=	PYGTK "Enable GUI and gtk dep (GUI files always installed)" on

MAN1=		deluge.1 deluge-console.1 deluge-gtk.1 deluge-web.1 deluged.1

PORTDOCS=	*

.include <bsd.port.pre.mk>

# things that happen when PREFIX differs from LOCALBASE
.if ${PREFIX} != ${LOCALBASE}

# only touch easy-install.pth if we installed it ourselves
.if !exists(${PYTHONPREFIX_SITELIBDIR}/easy-install.pth)
PLIST_FILES+=	${PYTHON_SITELIBDIR:S;${LOCALBASE}/;;}/easy-install.pth
.endif

# only touch site.py{c,o} if we installed it ourselves
.for file in site.py site.pyc site.pyo
.if !exists(${PYTHONPREFIX_SITELIBDIR}/${file})
PLIST_FILES+=	${PYTHON_SITELIBDIR:S;${LOCALBASE}/;;}/${file}
.endif
.endfor
.endif

.if !defined(WITHOUT_PYGTK)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}game>=1.8.1:${PORTSDIR}/devel/py-game \
		${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:${PORTSDIR}/devel/py-notify \
		xdg-utils>=1.0.2:${PORTSDIR}/devel/xdg-utils

PLIST_SUB+=	PYGTK=""
USE_GNOME+=	desktopfileutils librsvg2 pygtk2
INSTALLS_ICONS=	yes
.else
PLIST_SUB+=	PYGTK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/"new_release_check":/s|True,|False,|g ; \
		/"geoip_db_location":/s|/usr/share/GeoIP/GeoIP.dat|${LOCALBASE}/share/GeoIP/GeoIP.dat|g' \
			${WRKSRC}/deluge/core/preferencesmanager.py
	@${REINPLACE_CMD} -e '/"check_new_releases":/s|True,|False,|g ; \
		/"show_new_releases":/s|True,|False,|g' \
			${WRKSRC}/deluge/ui/gtkui/gtkui.py
	@${REINPLACE_CMD} -e 's|GTK|GTK;|' \
		${WRKSRC}/deluge/data/share/applications/deluge.desktop.in

post-install:
# do these by hand, else they wind up in the wrong place
	if [ ! -d ${PREFIX}/share/icons/hicolor/scalable/apps ]; then \
	${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/deluge/data/icons/scalable/apps/deluge.svg \
		${PREFIX}/share/icons/hicolor/scalable/apps
.for size in 16 22 24 32 36 48 64 72 96 128 192 256
	if [ ! -d ${PREFIX}/share/icons/hicolor/${size}x${size}/apps ]; then \
		${MKDIR} ${PREFIX}/share/icons/hicolor/${size}x${size}/apps ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/deluge/data/icons/hicolor/${size}x${size}/apps/deluge.png \
		${PREFIX}/share/icons/hicolor/${size}x${size}/apps
.endfor
	if [ ! -d ${PREFIX}/share/pixmaps ]; then \
	${MKDIR} ${PREFIX}/share/pixmaps ; \
	fi
.for file in png xpm
	${INSTALL_DATA} ${WRKSRC}/deluge/data/pixmaps/deluge.${file} \
		${PREFIX}/share/pixmaps
.endfor
.if !defined(WITHOUT_PYGTK)
	if [ ! -d ${PREFIX}/share/applications ]; then \
		${MKDIR} ${PREFIX}/share/applications ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/deluge/data/share/applications/deluge.desktop \
		${PREFIX}/share/applications
	@-update-desktop-database
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
# install man pages
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${man} ${MANPREFIX}/man/man1/
.endfor
# fix installation permissions
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG} -type f -exec ${CHMOD} ${SHAREMODE} {} \;

.include <bsd.port.post.mk>
