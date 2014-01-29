# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	xmms-status-plugin
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.hellion.org.uk/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS control applet for GNOME 2 panel / KDE tray

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

USES=		gettext gmake
USE_XORG=	x11 xpm
USE_CSTD=	gnu89
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,-Werror,,' ${WRKSRC}/configure

.include <bsd.port.mk>
