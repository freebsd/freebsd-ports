# New ports collection makefile for:	gnome-btdownload
# Date created:				21 October 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gnome-btdownload
PORTVERSION=	0.0.17
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-bt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple Gnome interface designed as a mime-sink for BitTorrent files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/BitTorrent/__init__.py:${PORTSDIR}/net/py-bittorrent-core

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix pygnome2 desktopfileutils
GNU_CONFIGURE=	yes

MAN1=		gnome-btdownload.1
DOCS=		AUTHORS COPYING ChangeLog README

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share/gnome|g' \
		${WRKSRC}/share/desktop/gnome-btdownload.desktop

post-install:
	@-update-desktop-database
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
