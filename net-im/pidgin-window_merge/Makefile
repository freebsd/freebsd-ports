PORTNAME=	window_merge
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	net-im
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	arcade@b1t.name
COMMENT=	One window interface for pidgin
WWW=		https://github.com/dm0-/window_merge

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpurple.so:net-im/libpurple
BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

USES=		autoreconf gmake gnome libtool localbase:ldflags pkgconfig
USE_GNOME=	intltool

INSTALL_TARGET=	install-strip
PLIST_FILES=	lib/pidgin/window_merge.so

USE_GITHUB=	yes
GH_ACCOUNT=	dm0-
GH_TAGNAME=	b4811ae1807a6c124fb06a717951bb2541be19f7

.include <bsd.port.mk>
