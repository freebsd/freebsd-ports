# New ports collection makefile for:	gtorrentviewer
# Date created:		2004-10-16
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gtorrentviewer
PORTVERSION=	0.2b
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GTorrentViewer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+2 viewer and editor for BitTorrent meta files

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20 gnomehier intlhack
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pixmapsdir=${PREFIX}/share/gnome/pixmaps \
		--with-desktopdir=${PREFIX}/share/gnome/applications

MAN1=		gtorrentviewer.1
DOCS=		AUTHORS COPYING ChangeLog README

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
