# ex:ts=8
# Ports collection makefile for:	gspoof
# Date created:			Jan 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gspoof
PORTVERSION=	3.2
PORTREVISION=	11
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Gspoof-3/${PORTVERSION}

MAINTAINER=	cm@therek.net
COMMENT=	Console/GTK+ TCP/IP Packets Forger

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

USE_GNOME=	gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

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
	${INSTALL_PROGRAM} ${WRKSRC}/gspoof ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/icon.png ${DATADIR}/pixmap
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
