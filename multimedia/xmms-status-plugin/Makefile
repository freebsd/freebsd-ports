# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	xmms-status-plugin
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.hellion.org.uk/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS control applet for GNOME 2 panel / KDE tray

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_XORG=	x11 xpm
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,-Werror,,' ${WRKSRC}/configure

.include <bsd.port.mk>
