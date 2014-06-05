# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$
#   $MCom: ports/net-p2p/gtorrentviewer/Makefile,v 1.4 2007/08/06 17:16:29 mezz Exp $

PORTNAME=	gtorrentviewer
PORTVERSION=	0.2b
PORTREVISION=	17
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/GTorrentViewer/${PORTVERSION}
DISTNAME=	GTorrentViewer-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	GTK+2 viewer and editor for BitTorrent meta files

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20 gnomehier intlhack
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pixmapsdir=${PREFIX}/share/pixmaps \
		--with-desktopdir=${PREFIX}/share/applications

PORTSCOUT=	skipv:0.2	# older than current version

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS COPYING ChangeLog README

.include <bsd.port.options.mk>
post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/main.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
