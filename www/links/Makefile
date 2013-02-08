# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	links
DISTVERSION=	2.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://links.twibright.com/download/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Lynx-like text WWW browser

LICENSE=	GPLv2

CONFLICTS=	links-0* links-hacked-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-ssl --without-pmshell --without-atheos \
			--without-gpm --without-fb --without-windows
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_OPENSSL=	yes
USE_BZIP2=	yes

OPTIONS_DEFINE=	DIRECTFB SVGALIB TRANS UTF8 X11

DIRECTFB_DESC=	DirectFB graphics support
SVGALIB_DESC=	SVGALib graphics support
TRANS_DESC=	Hack for background transparency
UTF8_DESC=	UTF-8 support
X11_DESC=	X11 graphics support

OPTIONS_DEFAULT=	UTF8 X11

MAN1=		links.1
PLIST_FILES=	bin/links

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma:${PORTSDIR}/archivers/xz
.endif

.if ${PORT_OPTIONS:MDIRECTFB} || ${PORT_OPTIONS:MSVGALIB} || ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--enable-graphics
.else
CONFIGURE_ARGS+=	--disable-graphics --without-libjpeg --without-libtiff
.endif

.if ${PORT_OPTIONS:MDIRECTFB}
LIB_DEPENDS+=	directfb-1.4.5:${PORTSDIR}/devel/directfb
CONFIGURE_ARGS+=	--with-directfb
.else
CONFIGURE_ARGS+=	--without-directfb
.endif

.if ${PORT_OPTIONS:MSVGALIB}
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=	--with-svgalib
.else
CONFIGURE_ARGS+=	--without-svgalib
.endif

.if ${PORT_OPTIONS:MTRANS}
EXTRA_PATCHES+=		${FILESDIR}/extra-terminal.c.diff
.endif

.if ${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=	--enable-utf8
.else
CONFIGURE_ARGS+=	--disable-utf8
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xproto
CONFIGURE_ARGS+=	--with-x
DESKTOP_ENTRIES="links" \
		"Lynx-like text WWW browser" \
		"${PREFIX}/share/pixmaps/links.xpm" \
		"links -g" \
		"Network;WebBrowser;" \
		false
PLIST_FILES+=	share/pixmaps/links.xpm
.else
CONFIGURE_ARGS+=	--without-x
.endif

post-patch:
	@${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/os_dep.h

.if ${PORT_OPTIONS:MX11}
post-install:
	@${INSTALL_DATA} ${WRKSRC}/graphics/links.xpm ${PREFIX}/share/pixmaps/links.xpm
.endif

.include <bsd.port.mk>
