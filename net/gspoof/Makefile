# ex:ts=8
# Ports collection makefile for:	gspoof
# Date created:			Jan 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gspoof
PORTVERSION=	3.2
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console/GTK+ TCP/IP Packets Forger

BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet

USE_GNOME=	gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet-prefix=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -O2|$${CFLAGS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-Wall -O2|@CFLAGS@|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|g ; \
		 s|/usr/share|${X11BASE}/share|g' ${WRKSRC}/gtk.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gspoof ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/icon.png ${DATADIR}/pixmap
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
