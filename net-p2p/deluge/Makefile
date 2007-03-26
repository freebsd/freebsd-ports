# New ports collection makefile for:	deluge
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deluge
PORTVERSION=	0.5.0
CATEGORIES=	net-p2p python
MASTER_SITES=	http://deluge-torrent.org/downloads/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A Bittorrent client, using Python, GTK+2 and Rasterbar libtorrent

LIB_DEPENDS=	boost_thread.3:${PORTSDIR}/devel/boost
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_GNOME=	pygtk2 desktopfileutils
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCS=		LICENSE README

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
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
