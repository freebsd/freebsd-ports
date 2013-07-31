# $FreeBSD$

PORTNAME=	multiwatch
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/multiwatch/releases-1.x/

MAINTAINER=	chris+freebsd@chrullrich.net
COMMENT=	Spawn-fcgi helper for forking multiple workers

LIB_DEPENDS=	ev:${PORTSDIR}/devel/libev

GNU_CONFIGURE=	yes

MAN1=		multiwatch.1
USES=		pkgconfig
USE_BZIP2=	yes
USE_GNOME=	glib20

# Help configure find libev.
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/multiwatch

.include <bsd.port.mk>
