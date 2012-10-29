# $FreeBSD$

PORTNAME=	multiwatch
PORTVERSION=	1.0.0
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/multiwatch/releases-1.x/

MAINTAINER=	chris+freebsd@chrullrich.net
COMMENT=	A spawn-fcgi helper for forking multiple workers

LIB_DEPENDS=	ev:${PORTSDIR}/devel/libev

GNU_CONFIGURE=	yes

MAN1=		multiwatch.1
USE_PKGCONFIG=	yes
USE_BZIP2=	yes
USE_GNOME=	_glib20

# Help configure find libev.
CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

PLIST_FILES=	bin/multiwatch

.include <bsd.port.mk>
