# ex:ts=8
# Ports collection makefile for:	gspoof
# Date created:			Jan 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gspoof
PORTVERSION=	2.1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	gtk
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e "s|gtk-config|${GTK_CONFIG}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gspoof ${PREFIX}/bin

.include <bsd.port.mk>
