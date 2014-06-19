# $FreeBSD$

PORTNAME=	libe-book
PORTVERSION=	0.0.3
CATEGORIES=	textproc
MASTER_SITES=	SF/libebook/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	00

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for import of reflowable e-book formats

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

USE_GNOME=	libxml2

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZLIB_CFLAGS="-DWEHAVEZLIBINBASE" ZLIB_LIBS="-DWEDOHAVEIT"
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-werror --without-docs --disable-tests
CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	${RM} -f ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
