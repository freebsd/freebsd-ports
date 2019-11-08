# Created by: ijliao
# $FreeBSD$

PORTNAME=	gspoof
PORTVERSION=	3.2
PORTREVISION=	16
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Gspoof-3/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console/GTK+ TCP/IP Packets Forger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnet.so:net/libnet

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet-prefix=${LOCALBASE}
USES=		gmake gnome

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|-Wall -O2|$${CFLAGS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-Wall -O2|@CFLAGS@|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|g ; \
		 s|/usr/share|${LOCALBASE}/share|g' ${WRKSRC}/gtk.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gspoof ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/icon.png ${STAGEDIR}${DATADIR}/pixmap

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
