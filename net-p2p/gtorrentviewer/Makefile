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

USES=		desktop-file-utils gmake gnome pkgconfig
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
