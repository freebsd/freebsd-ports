# New ports collection makefile for:	gtorrentviewer
# Date created:		2004-10-16
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gtorrentviewer
PORTVERSION=	0.2a
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GTorrentViewer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+2 viewer and editor for BitTorrent meta files

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20 gnomehier
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=yes

MAN1=		gtorrentviewer.1
DOCS=		AUTHORS COPYING ChangeLog README

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/applications|(prefix)/share/gnome/applications|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/pixmaps|(prefix)/share/gnome/pixmaps|g' \
		${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e 's|SYSTEM_PIXMAPS_DIR|PIXMAPS_DIR|g' \
		${WRKSRC}/src/mainwindow.h

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
