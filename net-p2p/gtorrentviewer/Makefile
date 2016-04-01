# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$
#   $MCom: ports/net-p2p/gtorrentviewer/Makefile,v 1.4 2007/08/06 17:16:29 mezz Exp $

PORTNAME=	gtorrentviewer
PORTVERSION=	0.2b
PORTREVISION=	19
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/GTorrentViewer/${PORTVERSION}
DISTNAME=	GTorrentViewer-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GTK+2 viewer and editor for BitTorrent meta files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake pkgconfig desktop-file-utils
USE_GNOME=	gtk20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pixmapsdir=${PREFIX}/share/pixmaps \
		--with-desktopdir=${PREFIX}/share/applications
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PORTSCOUT=	skipv:0.2	# older than current version

post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/main.c

.include <bsd.port.mk>
