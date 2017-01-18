# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	miro
PORTVERSION=	6.0
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.osuosl.org/pub/pculture.org/miro/src/ \
		http://ftp.osuosl.org/pub/pculture.org/miro/src/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Video player to get internet TV broadcasts

LICENSE=	GPLv2

BUILD_DEPENDS=	pyrexc:devel/pyrex \
		${PYTHON_SITELIBDIR}/webkit/__init__.py:www/py-webkitgtk \
		update-mime-database:misc/shared-mime-info \
		${LOCALBASE}/include/boost/numeric/ublas/matrix.hpp:devel/boost-libs \
		${LOCALBASE}/include/taglib/taglib.h:audio/taglib
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:databases/py-bsddb \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/dbus/glib.py:devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:devel/py-notify \
		${PYTHON_SITELIBDIR}/libtorrent.so:net-p2p/libtorrent-rasterbar-python \
		${PYTHON_SITELIBDIR}/webkit/webkit.so:www/py-webkitgtk \
		${PYTHON_SITELIBDIR}/gtk-2.0/gconf.so:x11-toolkits/py-gnome2 \
		${PYTHON_SITELIBDIR}/pycurl.so:ftp/py-pycurl \
		${PYTHON_SITELIBDIR}/mutagen/__init__.py:audio/py-mutagen

BUILD_WRKSRC=	${WRKSRC}/linux
INSTALL_WRKSRC=	${WRKSRC}/linux

USE_GNOME=	gconf2 gtk20
USE_GSTREAMER=	python gconf
USES=		gettext gmake pkgconfig desktop-file-utils python shared-mime-info shebangfix
SHEBANG_FILES=	resources/testdata/7digital-replies/generate.py \
		resources/testdata/echonest-replies/generate.py
USE_PYTHON=	distutils
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.SILENT:

post-patch:
.for file in setup.py plat/resources.py plat/options.py
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
	${PREFIX}/bin/miro --unittest
.endif

.include <bsd.port.post.mk>
