# New ports collection makefile for:	Democracy
# Date created:		30 November 2006
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	miro
PORTVERSION=	3.5.1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.osuosl.org/pub/pculture.org/miro/src/	\
		http://ftp.osuosl.org/pub/pculture.org/miro/src/

MAINTAINER=	armin@frozen-zone.org
COMMENT=	A video player to get internet TV broadcasts

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex				\
		${PYTHON_SITELIBDIR}/webkit/__init__.py:${PORTSDIR}/www/py-webkitgtk \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb	\
		${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite23	\
		${PYTHON_SITELIBDIR}/dbus/glib.py:${PORTSDIR}/devel/py-dbus	\
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify	\
		${PYTHON_SITELIBDIR}/libtorrent.so:${PORTSDIR}/net-p2p/libtorrent-rasterbar-15-python \
		${PYTHON_SITELIBDIR}/webkit/webkit.so:${PORTSDIR}/www/py-webkitgtk \
		${PYTHON_SITELIBDIR}/gtk-2.0/gconf.so:${PORTSDIR}/x11-toolkits/py-gnome2 \
		${PYTHON_SITELIBDIR}/pycurl.so:${PORTSDIR}/ftp/py-curl

BUILD_WRKSRC=	${WRKSRC}/linux
INSTALL_WRKSRC=	${WRKSRC}/linux

CONFLICTS=	Miro-[0-9]*

LICENSE=	GPLv2

USE_GNOME=	gconf2 gtk20
USE_GSTREAMER=	python
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}"
INSTALLS_ICONS=	yes
INSTALLS_EGGINFO=	yes

MANCOMPRESSED=	yes
MAN1=		miro.1 miro.real.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

.include <bsd.port.pre.mk>

.SILENT:

post-patch:
.for file in setup.py plat/resources.py
	${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%MANPREFIX%%|${MANPREFIX}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in miro.real
	${REINPLACE_CMD} -e 's|python2.4|${PYTHON_VERSION}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in run.sh
	${REINPLACE_CMD} -e 's|^PREFIX=.*|PREFIX=${PREFIX}|g' \
		${BUILD_WRKSRC}/${file}
.endfor

.if defined(MAINTAINER_MODE)
regression-test:	install
	LANG=C LC_ALL=C ${PREFIX}/bin/miro --unittest
.endif

.include <bsd.port.post.mk>
