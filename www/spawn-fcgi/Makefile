PORTNAME=	spawn-fcgi
PORTVERSION=	1.6.4
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/spawn-fcgi/releases-1.6.x/

MAINTAINER=	rsimmons0@gmail.com
COMMENT=	Spawns fastcgi applications
WWW=		https://redmine.lighttpd.net/projects/spawn-fcgi

USES=		cmake
CMAKE_ARGS=	-DCMAKE_MAN_DIR:string=${PREFIX}/share/man
USE_RC_SUBR=	spawn-fcgi

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/spawn-fcgi \
		share/man/man1/spawn-fcgi.1.gz

.include <bsd.port.pre.mk>

SUB_LIST+=	REQUIRE="DAEMON"

.include <bsd.port.post.mk>
