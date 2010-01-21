# New ports collection makefile for:	deluge
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deluge
PORTVERSION=	1.2.0
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.deluge-torrent.org/source/:deluge \
		http://libtorrent.googlecode.com/files/:libtorrent
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:deluge \
		${RBLT_DISTNAME}.tar.gz:libtorrent
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Bittorrent client, using Python, GTK+2 and Rasterbar libtorrent

BUILD_DEPENDS=	py*-setuptools>=0:${PORTSDIR}/devel/py-setuptools
LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS=	py*-gobject>=0:${PORTSDIR}/devel/py-gobject \
		py*-setuptools>=0:${PORTSDIR}/devel/py-setuptools \
		py*-simplejson>=0:${PORTSDIR}/devel/py-simplejson \
		py*-xdg>=0:${PORTSDIR}/devel/py-xdg \
		GeoIP>=0:${PORTSDIR}/net/GeoIP \
		py*-openssl>=0:${PORTSDIR}/security/py-openssl \
		py*-chardet>=0:${PORTSDIR}/textproc/py-chardet \
		py*-mako>=0:${PORTSDIR}/textproc/py-mako \
		py*-twistedWeb>=8.1:${PORTSDIR}/www/py-twistedWeb

USE_BZIP2=	yes
USE_GCC=	4.3+
WANT_GNOME=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes
MAKE_ENV=	PYTHONPATH="${PYTHONPREFIX_SITELIBDIR}"

MAN1=		deluge.1 deluge-console.1 deluge-gtk.1 deluge-web.1 deluged.1

PLIST_SUB=	VERSION="${PORTVERSION}" PYTHON_VER="${PYTHON_VER}"

OPENSSL_LDFLAGS=-rpath=${GCCRPATH}:${OPENSSLRPATH}

GCCRPATH=	`${CAT} ${WRKSRC}/LIBDIR`/../../../

RBLT_DISTNAME=	libtorrent-rasterbar-0.14.8

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PYGTK)
RUN_DEPENDS+=	py*-dbus>=0:${PORTSDIR}/devel/py-dbus \
		py*-game>=0:${PORTSDIR}/devel/py-game \
		py*-notify>=0:${PORTSDIR}/devel/py-notify \
		xdg-utils>=0:${PORTSDIR}/devel/xdg-utils
USE_GNOME+=	desktopfileutils librsvg2 pygtk2
INSTALLS_ICONS=	yes
.endif

.SILENT:

.if !defined(WITHOUT_PYGTK)
pre-everything::
	${ECHO_CMD} ""
	${ECHO_CMD} "Definable build options"
	${ECHO_CMD} "-----------------------"
	${ECHO_CMD} "WITHOUT_PYGTK=yes		Do not install pygtk dependency."
	${ECHO_CMD} ""
	${ECHO_CMD} "Keep in mind, choice WITHOUT_PYGTK still will installing a lot of GUI files that are for pygtk. The installation tool does not provide option to disable install the GUI files. These GUI files are harmless as long as you do not touch these or it won't work because it needs pygtk." | ${FMT} 75 75
.endif

post-extract:
	(cd ${WRKDIR} ; ${GZIP_CMD} -dc ${DISTDIR}/${RBLT_DISTNAME}.tar.gz \
		| ${TAR} -xf -)
	${LN} -sf ${WRKDIR}/${RBLT_DISTNAME} ${WRKSRC}/libtorrent

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
			${WRKSRC}/setup.py
	${REINPLACE_CMD} -e '/"new_release_check":/s|True,|False,|g' \
			${WRKSRC}/deluge/core/preferencesmanager.py
	${REINPLACE_CMD} -e '/"check_new_releases":/s|True,|False,|g ; \
		 /"show_new_releases":/s|True,|False,|g' \
			${WRKSRC}/deluge/ui/gtkui/gtkui.py

pre-configure:
	${DIRNAME} `${CC} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

do-build:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

do-install:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} install -c -O1 --prefix=${PREFIX})

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

.include <bsd.port.post.mk>
