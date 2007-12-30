# New ports collection makefile for:	deluge
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deluge
PORTVERSION=	0.5.8
CATEGORIES=	net-p2p python
MASTER_SITES=	http://download.deluge-torrent.org/tarball/${PORTVERSION}/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A Bittorrent client, using Python, GTK+2 and Rasterbar libtorrent

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl

WRKSRC=		${WRKDIR}/${PORTNAME}-torrent-${PORTVERSION}
USE_GNOME=	pygtk2 desktopfileutils librsvg2
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_ICONS=	yes

MAKE_ENV=	CC="${CC}" CXX="${CXX}"

DOCS=		LICENSE README

# Internal anonymizing browser needs gecko stuff in py-gnome-extras.
.if !defined(WITHOUT_GECKO)
RUN_DEPENDS+=	${pygnomeextras_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome-extras
USE_GECKO=	firefox seamonkey xulrunner mozilla
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
CFLAGS+=	-DAMD64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GECKO_LIB%%|${LOCALBASE}/lib/${GECKO}|g' \
			${WRKSRC}/scripts/deluge

post-install:
	@-update-desktop-database
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
