# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	links
PORTVERSION=	2.1.p20
PORTEPOCH=	1
CATEGORIES?=	www
MASTER_SITES=	http://links.twibright.com/download/
DISTNAME=	${PORTNAME}-2.1pre20

MAINTAINER?=	demon@FreeBSD.org
COMMENT=	Lynx-like text WWW browser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-javascript --with-ssl
CONFIGURE_ENV+=	CPPFLAGS='-I${LOCALBASE}/include'
LDFLAGS+=	-L${LOCALBASE}/lib

USE_OPENSSL=	yes
USE_BZIP2=	yes

OPTIONS=	SVGALIB "non-X11 graphics support" off \
		X11 "X11 graphics support" on

.include <bsd.port.pre.mk>

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--enable-graphics
OPTIONS_MESG=	"non-X11 graphics support enabled, "
.else
CONFIGURE_ARGS+=	--without-svgalib
OPTIONS_MESG=	"non-X11 graphics support disabled, "
.endif

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
USE_XLIB=	yes
CONFIGURE_ARGS+=	--enable-graphics --with-x
OPTIONS_MESG+=	"X11 graphics support enabled."
.else
CONFIGURE_ARGS+=	--without-x
OPTIONS_MESG+=	"X11 graphics support disabled."
.endif

MAN1=		links.1
PLIST_FILES=	bin/links

pre-everything::
		@${ECHO_MSG} ${OPTIONS_MESG}

post-patch:
	@${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/default.c

.include <bsd.port.post.mk>
