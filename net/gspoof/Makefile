# Created by: ijliao
# $FreeBSD$

PORTNAME=	gspoof
PORTVERSION=	3.2
PORTREVISION=	15
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Gspoof-3/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console/GTK+ TCP/IP Packets Forger

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USES=		gmake

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wall -O2|$${CFLAGS}|g; \
		 s|libnet-config|${LIBNET_CONFIG}|' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-Wall -O2|@CFLAGS@|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|g ; \
		 s|/usr/share|${LOCALBASE}/share|g' ${WRKSRC}/gtk.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gspoof ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/icon.png ${STAGEDIR}${DATADIR}/pixmap
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
