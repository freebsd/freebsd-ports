# New ports collection makefile for:	deluge
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deluge
DISTVERSION=	1.3.0_rc1
PORTEPOCH=	1
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.deluge-torrent.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bittorrent client using Python, GTK+2 and libtorrent-rasterbar

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0.6:${PORTSDIR}/devel/py-setuptools
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs \
		GeoIP:${PORTSDIR}/net/GeoIP
RUN_DEPENDS=	boost-python-libs>=1.41.0:${PORTSDIR}/devel/boost-python-libs \
		${PYTHON_PKGNAMEPREFIX}gobject>=2.20.0:${PORTSDIR}/devel/py-gobject \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0.6:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.18:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}libtorrent-rasterbar$>=0.15.1:${PORTSDIR}/net-p2p/libtorrent-rasterbar-15-python \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.8:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}chardet>=1.0.1:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}mako>=0.2.5:${PORTSDIR}/textproc/py-mako

USE_RC_SUBR=	deluged
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_PYTHON=	2.5+
USE_TWISTED=	web
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

OPTIONS=	PYGTK "Enable GUI and gtk dep (GUI files always installed)" on \
		PSYCO "Enable devel/py-psyco optimization (i386 only)" off

MAN1=		deluge.1 deluge-console.1 deluge-gtk.1 deluge-web.1 deluged.1

PORTDOCS=	*

PLIST_SUB=	VERSION="${DISTVERSION}" PYTHON_VER="${PYTHON_VER}"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
.undef WITH_PSYCO
WITHOUT_PSYCO=	yes
.endif

.if defined(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

EXTRA_PATCHES+=	${FILESDIR}/extra-psyco-patch-deluge__main.py \
		${FILESDIR}/extra-psyco-patch-deluge__ui__console__main.py \
		${FILESDIR}/extra-psyco-patch-deluge__ui__gtkui__gtkui.py \
		${FILESDIR}/extra-psyco-patch-deluge__ui__web__web.py
.endif

.if !defined(WITHOUT_PYGTK)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.83:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}game>=1.8.1:${PORTSDIR}/devel/py-game \
		${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:${PORTSDIR}/devel/py-notify \
		xdg-utils>=1.0.2:${PORTSDIR}/devel/xdg-utils

USE_GNOME+=	desktopfileutils librsvg2 pygtk2
INSTALLS_ICONS=	yes
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
			${WRKSRC}/setup.py
	${REINPLACE_CMD} -e '/"new_release_check":/s|True,|False,|g ; \
		 /"geoip_db_location":/s|/usr/share/GeoIP/GeoIP.dat|${LOCALBASE}/share/GeoIP/GeoIP.dat|g' \
			${WRKSRC}/deluge/core/preferencesmanager.py
	${REINPLACE_CMD} -e '/"check_new_releases":/s|True,|False,|g ; \
		 /"show_new_releases":/s|True,|False,|g' \
			${WRKSRC}/deluge/ui/gtkui/gtkui.py

post-install:
.if !defined(WITHOUT_PYGTK)
	-update-desktop-database
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
# fix installation permissions
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/deluge -type f -exec ${CHMOD} ${SHAREMODE} {} \;

.include <bsd.port.post.mk>
