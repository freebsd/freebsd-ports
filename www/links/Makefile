# Created by: Michael Vasilenko <acid@stu.cn.ua>
# $FreeBSD$

PORTNAME=	links
DISTVERSION=	2.13
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://links.twibright.com/download/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lynx-like text WWW browser

LICENSE=	GPLv2

CONFLICTS=	links-0* links-hacked-[0-9]* links1-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-ssl --without-pmshell --without-atheos \
			--without-gpm --without-fb --without-windows
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		cpe ssl tar:bzip2

CPE_VENDOR=	twibright

OPTIONS_DEFINE=	CIPHERSTRING DIRECTFB IPV6 SVGALIB THREADS TRANS UTF8 X11

CIPHERSTRING_DESC=	Select the OpenSSL ciphers used via CIPHERSTRING
DIRECTFB_DESC=	DirectFB graphics support
SVGALIB_DESC=	SVGALib graphics support
TRANS_DESC=	Hack for background transparency
UTF8_DESC=	UTF-8 support
X11_DESC=	X11 graphics support

OPTIONS_DEFAULT=	UTF8 X11

PLIST_FILES=	bin/links man/man1/links.1.gz

DIRECTFB_LIB_DEPENDS=	libdirectfb.so:devel/directfb
DIRECTFB_CONFIGURE_WITH=directfb

IPV6_CONFIGURE_WITH=	ipv6

SVGALIB_LIB_DEPENDS=	libvga.so:graphics/svgalib
SVGALIB_CONFIGURE_WITH=	svgalib

THREADS_CFLAGS=	-DHAVE_PTHREADS
THREADS_LDFLAGS=-pthread

TRANS_EXTRA_PATCHES=	${FILESDIR}/extra-terminal.c.diff

UTF8_CONFIGURE_ENABLE=	utf8

X11_USE=	xorg=x11,xproto
X11_CONFIGURE_WITH=	x
X11_PLIST_FILES=	share/pixmaps/links.xpm

.include <bsd.port.options.mk>

#CIPHERSTRING must be a valid OpenSSL cipher string(see ciphers(1)):
CIPHERSTRING?=	HIGH:!SSLv2:!aNULL:!eNULL:@STRENGTH

.if ${PORT_OPTIONS:MDIRECTFB} || ${PORT_OPTIONS:MSVGALIB} || ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff
USES+=		jpeg
CONFIGURE_ARGS+=	--enable-graphics
.else
CONFIGURE_ARGS+=	--disable-graphics --without-libjpeg --without-libtiff
.endif

.if ${PORT_OPTIONS:MX11}
DESKTOP_ENTRIES="links" \
		"Lynx-like text WWW browser" \
		"${PREFIX}/share/pixmaps/links.xpm" \
		"links -g" \
		"Network;WebBrowser;" \
		false
.endif

post-patch:
	@${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/os_dep.h
	@${REINPLACE_CMD} -e "/LIBS=/{s/-lpthread/-pthread/;s/-ldl//;}" \
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MCIPHERSTRING}
	@${REINPLACE_CMD} -e '/SSL_CTX_set_options/ \
	s/;/; SSL_CTX_set_cipher_list(context, "${CIPHERSTRING}");/' \
		${WRKSRC}/https.c
.endif

.if ${PORT_OPTIONS:MX11}
post-install:
	${INSTALL_DATA} ${WRKSRC}/graphics/links.xpm ${STAGEDIR}${PREFIX}/share/pixmaps/links.xpm
.endif

.include <bsd.port.mk>
