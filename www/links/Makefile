# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	links
DISTVERSION=	2.3
PORTEPOCH=	1
CATEGORIES?=	www
MASTER_SITES=	http://links.twibright.com/download/

MAINTAINER?=	demon@FreeBSD.org
COMMENT=	Lynx-like text WWW browser

CONFLICTS=	links-0*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-ssl --without-pmshell --without-atheos \
			--without-gpm --without-fb
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_OPENSSL=	yes
USE_BZIP2=	yes

OPTIONS=	SVGALIB "non-X11 graphics support" off \
		DIRECTFB "directfb driver support" off \
		IPV6 "IPv6 support" off \
		X11 "X11 graphics support" on \
		UTF8 "With UTF-8 support" on \
		TRANS "Hack for background transparency" off

.include <bsd.port.options.mk>

.ifdef(WITH_SVGALIB) || defined(WITH_X11) || defined(WITH_DIRECTFB)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png \
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

.if defined(WITH_IPV6)
USE_AUTOTOOLS+=	autoconf
MASTER_SITES+=	http://xpisar.wz.cz/links-ipv6/:ipv6
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} links-2.2-ipv6-2.diff:ipv6
EXTRA_PATCHES+= ${WRKDIR}/links-2.2-ipv6-2.diff
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	x11 xproto
CONFIGURE_ARGS+=	--with-x
DESKTOP_ENTRIES="links" \
		"Lynx-like text WWW browser" \
		"links" \
		"links -g" \
		"Application;Network;WebBrowser;" \
		false
PLIST_FILES+=	share/pixmaps/links.xpm
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if defined(WITHOUT_UTF8)
CONFIGURE_ARGS+=	--disable-utf8
.endif

.if defined(WITH_TRANS)
EXTRA_PATCHES+=		${FILESDIR}/extra-terminal.c.diff
.endif

MAN1=		links.1
PLIST_FILES+=	bin/links

.ifdef(WITH_IPV6)
post-extract:
#adjust the ipv6 patch for links 2.3*
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/links-2.2-ipv6-2.diff ${WRKDIR}
	@${REINPLACE_CMD} -E -e 's!void (lookup_fn|end_real_lookup)!static &!' \
		-e 's!^(\+\+\+|---) (a|b)/!\1 !' ${WRKDIR}/links-2.2-ipv6-2.diff
.endif

post-patch:
	@${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/os_dep.h
#replace a deprecated indirect selection with png_jumpbuf()
	@${REINPLACE_CMD} -e 's!png_ptr->jmpbuf!png_jmpbuf(png_ptr)!' ${WRKSRC}/png.c

.if !defined(WITHOUT_X11)
post-install:
	@${INSTALL_DATA} ${WRKSRC}/graphics/links.xpm ${PREFIX}/share/pixmaps/links.xpm
.endif

.include <bsd.port.mk>
