# New ports collection makefile for:	links-hacked
# Date created:		24 September 2011
# Whom:			Peter Vereshagin <peter@vereshagin.org>
#
# $FreeBSD$
#

PORTNAME=	links-hacked
DISTVERSION=	101110
PORTREVISION=	1
CATEGORIES?=	www
MASTER_SITES=	http://xray.sai.msu.ru/~karpov/links-hacked/downloads/ http://links-hacked.nm.ru/

MAINTAINER=	peter@vereshagin.org
COMMENT=	Hacked version of a Links WWW browser

LIB_DEPENDS+=	execinfo:${PORTSDIR}/devel/libexecinfo \
		gdbm:${PORTSDIR}/databases/gdbm

CONFLICTS=	links-[0-9]*

USE_AUTOTOOLS?=	autoconf autoheader aclocal automake
AUTOMAKE_ARGS?=	-a -c

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-ssl --without-pmshell --without-atheos \
			--without-fb --enable-form-saving --enable-javascript
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

USE_OPENSSL=	yes

OPTIONS=	SVGALIB "non-X11 graphics support" off \
		DIRECTFB "directfb driver support" off \
		X11 "X11 graphics support" on \
		FORMSAVE "Enable forms saving" on \
		JS "Enable Javascript (very basic)" on \
		FREETYPE "Enable Freetype renderer" on

.include <bsd.port.options.mk>

.ifdef(WITH_SVGALIB) || defined(WITH_X11) || defined(WITH_DIRECTFB)
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--enable-graphics
.else
CONFIGURE_ARGS+=	--disable-graphics --without-libjpeg --without-libtiff
.endif

.ifdef(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=	--with-svgalib
.else
CONFIGURE_ARGS+=	--without-svgalib
.endif

.ifdef(WITH_DIRECTFB)
LIB_DEPENDS+=	directfb-1.4.5:${PORTSDIR}/devel/directfb
CONFIGURE_ARGS+=	--with-directfb
.else
CONFIGURE_ARGS+=	--without-directfb
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	x11 xproto
CONFIGURE_ARGS+=	--with-x
DESKTOP_ENTRIES="Links" \
		"Lynx-like hacked WWW browser" \
		"${PREFIX}/share/pixmaps/links.xpm" \
		"links -g" \
		"Network;WebBrowser;" \
		false
PLIST_FILES+=	share/pixmaps/links.xpm
.else
CONFIGURE_ARGS+=	--without-x
.endif

.ifdef(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.ifdef(WITH_FORMSAVE)
CONFIGURE_ARGS+=	--enable-form-saving
.else
CONFIGURE_ARGS+=	--disable-form-saving
.endif

.ifdef(WITH_JS)
CONFIGURE_ARGS+=	--enable-javascript
.else
CONFIGURE_ARGS+=	--disable-javascript
.endif

MAN1=		links.1
PLIST_FILES+=	bin/links

.if !defined(WITHOUT_X11)
post-install:
	@${INSTALL_DATA} ${WRKSRC}/graphics/links.xpm ${PREFIX}/share/pixmaps/links.xpm
.endif

.include <bsd.port.mk>
