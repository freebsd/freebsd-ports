PORTNAME=	driftnet
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to grab images out of (your) TCP connections
WWW=		https://www.ex-parrot.com/~chris/driftnet/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	makedepend:devel/makedepend
LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libwebsockets.so:net/libwebsockets

USES=		autoreconf gettext-runtime gmake gnome jpeg localbase:ldflags \
		pkgconfig xorg
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	deiv
USE_GNOME=	gtk30
USE_XORG=	x11 xext xi

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/driftnet \
		share/man/man1/driftnet.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
