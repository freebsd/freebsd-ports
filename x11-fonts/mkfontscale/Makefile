PORTNAME=	mkfontscale
PORTVERSION=	1.2.3
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Creates an index of scalable font files for X
WWW=		https://www.xfree86.org/4.3.0/mkfontscale.1.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	xorgproto fontenc

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/mkfontdir \
		bin/mkfontscale \
		share/man/man1/mkfontdir.1.gz \
		share/man/man1/mkfontscale.1.gz

.include <bsd.port.mk>
