# New ports collection makefile for:	deluge
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deluge
PORTVERSION=	0.5.9.4
CATEGORIES=	net-p2p python
MASTER_SITES=	http://ftp.osuosl.org/pub/deluge/source/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Bittorrent client, using Python, GTK+2 and Rasterbar libtorrent

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl

DEPRECIATED=	use net-p2p/deluge instead
EXPIRATION_DATE=	2009-06-01

LATEST_LINK=	${PORTNAME}05

WRKSRC=		${WRKDIR}/${PORTNAME}-torrent-${PORTVERSION}
USE_GNOME=	pygtk2 desktopfileutils librsvg2
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_ICONS=	yes

DOCS=		LICENSE README

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64" || ${ARCH} == "amd64"
CFLAGS+=	-DAMD64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/setup.py

post-install:
	@-update-desktop-database
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
