# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/libxml++26/Makefile,v 1.43 2011/04/18 19:58:29 kwm Exp $

PORTNAME=	libxml++
PORTVERSION=	2.40.1
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	bland@FreeBSD.org
COMMENT=	XML API for C++

USES+=		tar:xz compiler:c++11-lang
USE_CXXSTD=	c++11

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

.if !defined(REFERENCE_PORT)

USES+=		gmake libtool pathfix pkgconfig gnome
USE_GNOME=	glibmm libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation
INSTALL_TARGET=	install-strip
BINARY_WRAPPERS=	gm4

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^library_configdir =/s/libdir/includedir/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^Cflags:/s/libdir/includedir/' \
		${WRKSRC}/libxml++-2.6.pc.in

.include <bsd.port.mk>

.endif
