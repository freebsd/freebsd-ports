PORTNAME=	spawn-fcgi
PORTVERSION=	1.6.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.lighttpd.net/spawn-fcgi/releases-1.6.x/

PATCH_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spawns fastcgi applications
WWW=		https://redmine.lighttpd.net/projects/spawn-fcgi

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson
USE_RC_SUBR=	spawn-fcgi

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/spawn-fcgi \
		share/man/man1/spawn-fcgi.1.gz

.include <bsd.port.pre.mk>

SUB_LIST+=	REQUIRE="DAEMON"

.include <bsd.port.post.mk>
