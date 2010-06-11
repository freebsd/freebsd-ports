# New ports collection makefile for:	deluge
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deluge
PORTVERSION=	1.1.9
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.deluge-torrent.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Bittorrent client, using Python, GTK+2 and Rasterbar libtorrent

BUILD_DEPENDS=	easy_install-${PYTHON_VER}:${PORTSDIR}/devel/py-setuptools
LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS=	easy_install-${PYTHON_VER}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_GCC=	4.4+
MAKE_ENV=	PYTHONPATH="${PYTHONPREFIX_SITELIBDIR}"

OPTIONS=	PSYCO "Enable devel/py-psyco optimization support (i386)" off

MAN1=		deluge.1 deluged.1

PLIST_SUB=	VERSION="${PORTVERSION}" PYTHON_VER="${PYTHON_VER}"

.if !defined(WITHOUT_PYGTK)
RUN_DEPENDS+=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify
USE_GNOME=	pygtk2 desktopfileutils librsvg2
INSTALLS_ICONS=	yes
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
.undef WITH_PSYCO

WITHOUT_PSYCO=	yes
.endif

.if defined(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-deluge__main.py
.endif

.if (exists(${LOCALBASE}/lib/libboost_iostreams.so) && \
	!exists(${LOCALBASE}/lib/libboost_python.so))
IGNORE=	cannot find dependency: The boost exists but not with Python support. Please uninstall boost and install boost-python or reinstall boost with Python support
.endif

.if !defined(WITHOUT_PYGTK)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Definable build options"
	@${ECHO_CMD} "-----------------------"
	@${ECHO_CMD} "WITHOUT_PYGTK=yes		Do not install pygtk dependency."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Keep in mind, choice WITHOUT_PYGTK still will installing a lot of GUI files that are for pygtk. The installation tool does not provide option to disable install the GUI files. These GUI files are harmless as long as you do not touch these or it won't work because it needs pygtk." | ${FMT} 75 75
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
			${WRKSRC}/setup.py

do-build:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

do-install:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} install -c -O1 --prefix=${PREFIX})

post-install:
.if !defined(WITHOUT_PYGTK)
	@-update-desktop-database
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ChangeLog LICENSE README
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
