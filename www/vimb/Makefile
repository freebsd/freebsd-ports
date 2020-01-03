# $FreeBSD$

PORTNAME=	vimb
DISTVERSION=	3.6.0
CATEGORIES=	www

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Vim like browser

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c11 desktop-file-utils gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	fanglingsu
GH_PROJECT=	vimb
USE_GNOME=	cairo gdkpixbuf2 gtk30

MAKE_ARGS=	MANPREFIX=${STAGEDIR}${PREFIX}/man \
		V=1 \
		version="${DISTVERSION}"
LDFLAGS+=	-Wl,--as-needed

PLIST_FILES=	bin/vimb \
		lib/vimb/webext_main.so \
		man/man1/vimb.1.gz \
		share/applications/vimb.desktop

post-patch:
# .git/index needs to exist to generate version.h...
	${MKDIR} ${WRKSRC}/.git/index

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vimb \
		${STAGEDIR}${PREFIX}/lib/vimb/webext_main.so

.include <bsd.port.mk>
