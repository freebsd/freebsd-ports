# New ports collection makefile for:	gtorrentviewer
# Date created:		2004-10-16
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#   $MCom: ports/net-p2p/gtorrentviewer/Makefile,v 1.4 2007/08/06 17:16:29 mezz Exp $
#

PORTNAME=	gtorrentviewer
PORTVERSION=	0.2b
PORTREVISION=	16
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/GTorrentViewer/${PORTVERSION}
DISTNAME=	GTorrentViewer-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	GTK+2 viewer and editor for BitTorrent meta files

PORTSCOUT=	skipv:0.2	# older than current version

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20 gnomehier intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pixmapsdir=${PREFIX}/share/pixmaps \
		--with-desktopdir=${PREFIX}/share/applications

MAN1=		gtorrentviewer.1
DOCS=		AUTHORS COPYING ChangeLog README

post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/main.c

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
