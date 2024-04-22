PORTNAME=	libXft
DISTVERSION=	2.3.7
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Client-sided font API for X applications
WWW=		https://www.freedesktop.org/wiki/Software/Xft/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xorgproto xrender

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

post-extract:
	@${CP} ${FILESDIR}/xft-config.in \
		${WRKSRC}/xft-config.in

post-patch:
	@${REINPLACE_CMD} -e '/ac_config_files/s|xft\.pc|xft\.pc xft-config|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xft-config \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
