# Created by: Babak Farrokhi
# $FreeBSD$

PORTNAME=	tapidbus
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/tapioca-voip/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction layer for interprocess communication

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		pathfix pkgconfig gmake libtool
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|\-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
