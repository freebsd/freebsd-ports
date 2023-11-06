PORTNAME=	libxml++
PORTVERSION=	2.91.3
PORTREVISION?=	0
CATEGORIES=	textproc
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	XML API for C++
WWW=		https://libxmlplusplus.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		tar:xz compiler:c++11-lang

PLIST_SUB=	VERSION="3.0" API_VERSION="3.0"

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
		${WRKSRC}/libxml++.pc.in

.include <bsd.port.mk>
