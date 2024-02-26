PORTNAME=	multiwatch
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/multiwatch/releases-1.x/

MAINTAINER=	chris@chrullrich.net
COMMENT=	Spawn-fcgi helper for forking multiple workers
WWW=		https://redmine.lighttpd.net/projects/multiwatch/wiki

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libev.so:devel/libev

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

USES=		gnome pkgconfig tar:bzip2
USE_GNOME=	glib20

# Help configure find libev.
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/multiwatch \
		share/man/man1/multiwatch.1.gz

.include <bsd.port.mk>
