# New ports collection makefile for:	gnome-btdownload
# Date created:				21 October 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gnome-btdownload
PORTVERSION=	0.0.20
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-p2p gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-bt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple Gnome interface designed as a mime-sink for BitTorrent files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/BitTorrent/__init__.py:${PORTSDIR}/net-p2p/py-bittorrent-core

IGNORE=does not run with BitTorrent 4.x yet

USE_X_PREFIX=	yes
USE_GNOME=	desktopfileutils gnomehack gnomeprefix pygnome2
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		gnome-btdownload.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11PREFIX%%|${PREFIX}|g ; \
		 s|gnome\.vfs|gnomevfs|g' ${WRKSRC}/src/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share/gnome|g' \
		${WRKSRC}/share/desktop/gnome-btdownload.desktop

post-install:
	@-update-desktop-database
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
