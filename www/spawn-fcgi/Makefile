PORTNAME=	spawn-fcgi
PORTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/spawn-fcgi/releases-1.6.x/

MAINTAINER=	rsimmons0@gmail.com
COMMENT=	Spawns fastcgi applications

USES=		cmake
CMAKE_ARGS=	-DCMAKE_MAN_DIR:string=${MANPREFIX}/man
USE_RC_SUBR=	spawn-fcgi

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/spawn-fcgi \
		man/man1/spawn-fcgi.1.gz

.include <bsd.port.pre.mk>

SUB_LIST+=	REQUIRE="DAEMON"

.include <bsd.port.post.mk>
